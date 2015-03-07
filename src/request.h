#ifndef _CROSSAVER_H_REQUEST
#define _CROSSAVER_H_REQUEST

#include <SFML/Window/WindowHandle.hpp>

class Request {

    public:
        Request();

        ~Request();

        bool isPreview();

        sf::WindowHandle getHandle();

    private:
        bool m_preview;

        sf::WindowHandle m_handle;

};

#endif // _CROSSAVER_H_REQUEST
