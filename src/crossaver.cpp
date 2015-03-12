#include <crossaver.h>

#include <SFML/Window/Event.hpp>

#include "requestType.h"
#include "request.h"
#include "constants.h"

#ifdef _WIN32
#include <Windows.h>

// custom callback for handling preview window close event
static long CALLBACK chldWndProc(HWND, UINT, WPARAM, LPARAM);
static bool destroyReceived = false;
#endif // _WIN32

Crossaver::Crossaver() : m_renderWindow(NULL), m_isPreview(false) {}

Crossaver::~Crossaver() {
    if (m_renderWindow)
        delete m_renderWindow;
}

int Crossaver::run(int argc, char** argv) {
    Request request(argc, argv);
    sf::Event toProcess;
    int mouseX = -1; int mouseY = -1;

#ifdef _WIN32
    WNDCLASS childClass; // class used for creating a window
    HWND childWindow = NULL; // child window used to display the preview
    HINSTANCE hInstance = GetModuleHandle(NULL);
#endif // _WIN32

    if (CONFIG == request.getRequestType()) {

#ifdef _WIN32
        MessageBox(request.getHandle(), "Configuration not yet implemented",
                "Information", MB_OK | MB_ICONASTERISK);
#endif // _WIN32

        return EXIT_SUCCESS;
    }

    m_isPreview = request.getRequestType() == PREVIEW;
    if (m_isPreview || (IS_FULL_SCREEN_VIA_HANDLE
                && FULL_SCREEN == request.getRequestType())) {

#ifdef _WIN32
        // filling our custom class' fields in order to create another window
        childClass.style = 0;
        childClass.lpfnWndProc = chldWndProc;
        childClass.cbClsExtra = 0;
        childClass.cbWndExtra = 0;
        childClass.hInstance = hInstance;
        childClass.hIcon = NULL;
        childClass.hCursor = NULL;
        childClass.hbrBackground = NULL;
        childClass.lpszMenuName = NULL;
        childClass.lpszClassName = "childWindowClass";
        // registering the new class in the OS
        RegisterClass(&childClass);
        // creating a window with our custom class
        childWindow = CreateWindow("childWindowClass", "Crossaver",
                WS_CHILD, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                CW_USEDEFAULT, request.getHandle(), NULL, hInstance, NULL);

        if (!childWindow)
            return EXIT_FAILURE;
#endif // _WIN32

        m_renderWindow = new sf::RenderWindow(request.getHandle());
    } else if (FULL_SCREEN == request.getRequestType()) {
        m_renderWindow = new sf::RenderWindow(sf::VideoMode::getDesktopMode(),
                "Crossaver", sf::Style::Fullscreen);
        m_renderWindow->setMouseCursorVisible(false);
    } else {
        // DEBUG
        m_renderWindow = new sf::RenderWindow(sf::VideoMode(800, 600, 32),
                "Crossaver");
    }

    if (!init())
        return EXIT_FAILURE;

    // main render loop
    while (m_renderWindow->isOpen()) {

#ifdef _WIN32
        // check for the destroying of the preview window
        if (destroyReceived) {
            m_renderWindow->close();
            continue;
        }
#endif // _WIN32

        // queued events handling
        while (m_renderWindow->pollEvent(toProcess)) {
            // asking for app closing
            if (sf::Event::Closed == toProcess.type) {
                m_renderWindow->close();
                continue;
            }
            if (!IS_FULL_SCREEN_VIA_HANDLE
                    && FULL_SCREEN == request.getRequestType()) {
                if (sf::Event::KeyPressed == toProcess.type ||
                        sf::Event::KeyReleased == toProcess.type ||
                        sf::Event::MouseButtonPressed == toProcess.type ||
                        sf::Event::MouseButtonReleased == toProcess.type) {
                    m_renderWindow->close();
                    continue;
                }
                if (sf::Event::MouseMoved == toProcess.type) {
                    if (mouseX < 0 || mouseY < 0) {
                        mouseX = toProcess.mouseMove.x;
                        mouseY = toProcess.mouseMove.y;
                    }
                    else if (mouseX != toProcess.mouseMove.x
                            || mouseY != toProcess.mouseMove.y) {
                        m_renderWindow->close();
                        continue;
                    }
                }
            }
        }
        // effective frame rendering
        if (!render())
            m_renderWindow->close();
    }

    if (!shutDown())
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

bool Crossaver::init() {
    return true;
}

bool Crossaver::shutDown() {
    return true;
}

bool Crossaver::isPreview() {
    return m_isPreview;
}

#ifdef _WIN32
long CALLBACK chldWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    if (uMsg == WM_DESTROY)
        destroyReceived = true;
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
#endif // _WIN32
