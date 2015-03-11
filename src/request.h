#ifndef _CROSSAVER_H_REQUEST
#define _CROSSAVER_H_REQUEST

#include <SFML/Window/WindowHandle.hpp>

#include "requestType.h"

class Request {

    public:
        Request(int argc, char** argv);

        ~Request();

        RequestType getRequestType();

        bool isFullScreenViaHandle();

        sf::WindowHandle getHandle();

    private:
        bool isWindowFullScreen();

        RequestType m_requestType;

        sf::WindowHandle m_handle;

};

#endif // _CROSSAVER_H_REQUEST
