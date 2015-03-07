#include "request.h"

#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>

#ifdef __unix__
#include <cstdlib>
#include <cstdio>
#endif // __unix__

Request::Request() {
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
            return;
        }
    }
    m_requestType = SCREENSAVER;
#endif // __unix__
}

Request::~Request() {}

RequestType Request::getRequestType() {
    return m_requestType;
}

bool Request::isFullScreenViaHandle() {
    // XScreensaver gives the screensaver a handle on a fullscreen window
#ifdef __unix__
    return true;
#endif // __unix__
    return false;
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
