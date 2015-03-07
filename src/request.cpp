#include "request.h"

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
            m_preview = true;
            return;
        }
    }
    m_preview = false;
#endif // __unix__
}

Request::~Request() {}

bool Request::isPreview() {
    return m_preview;
}

sf::WindowHandle Request::getHandle() {
    return m_handle;
}
