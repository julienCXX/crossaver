#include "request.h"

#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>

#ifdef _WIN32
#include <cstdlib>
#include <cstring>
#endif // _WIN32
#ifdef __unix__
#include <cstdlib>
#include <cstdio>
#endif // __unix__

Request::Request(int argc, char** argv) {
    m_requestType = DEBUG;

#ifdef _WIN32
    // read request parameters from command line
    char* handle;
    if (1 == argc) { // no arguments
        return;
    }
    // at least one argument
    if (!strncmp(argv[1], "/s", 2)) {
        m_requestType = SCREENSAVER;
        return;
    }
    if (!strncmp(argv[1], "/c", 2)) {
        // maybe config mode, formatted like "/c:xxxxx"
        if (3 >= strlen(argv[1])) {
            return;
        }
        // try to extract "xxxxx"
        m_handle = (sf::WindowHandle) atoi(argv[1] + 3);
        m_requestType = CONFIG;
        return;
    }
    if (2 >= argc) {
        return;
    }
    // at least 2 arguments
    if (!strncmp(argv[1], "/p", 2)) {
        // maybe preview mode, formatted like "/p xxxxx"
        m_handle = (sf::WindowHandle) atoi(argv[2]);
        m_requestType = PREVIEW;
    }
#endif // _WIN32

#ifdef __unix__
    // see xscreensaver's utils/vroot.h
    const char* winId = getenv("XSCREENSAVER_WINDOW");
    if (winId && *winId) {
        unsigned long int id;
        char c;
        if (1 == sscanf(winId, " 0x%lx %c", &id, &c) ||
                1 == sscanf(winId, " %lu %c",  &id, &c)) {
            m_handle = (sf::WindowHandle) id;
            m_requestType = isWindowFullScreen() ? SCREENSAVER : PREVIEW;
        }
    }
#endif // __unix__
}

Request::~Request() {}

RequestType Request::getRequestType() {
    return m_requestType;
}

sf::WindowHandle Request::getHandle() {
    return m_handle;
}

bool Request::isWindowFullScreen() {
    sf::VideoMode vm = sf::VideoMode::getDesktopMode();
    sf::Window win(m_handle);
    sf::Vector2u size(win.getSize());
    return size.x == vm.width && size.y == vm.height;
}
