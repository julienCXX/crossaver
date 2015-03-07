#include <crossaver.h>

#include "request.h"

Crossaver::Crossaver() : m_renderWindow(NULL) {}

Crossaver::~Crossaver() {
    if (m_renderWindow)
        delete m_renderWindow;
}

int Crossaver::run() {
    Request request;
    sf::Event toProcess;
    int mouseX = -1; int mouseY = -1;

    if (request.isPreview()) {
        m_renderWindow = new sf::Window(request.getHandle());
    } else {
        m_renderWindow = new sf::Window(sf::VideoMode(800, 600, 32),
                "Crossaver");
        m_renderWindow->setMouseCursorVisible(false);
    }

    if (!init())
        return EXIT_FAILURE;

    // main render loop
    while (m_renderWindow->isOpen()) {
        // queued events handling
        while (m_renderWindow->pollEvent(toProcess)) {
            // asking for app closing
            if (sf::Event::Closed == toProcess.type) {
                m_renderWindow->close();
                continue;
            }
            if (!request.isPreview()) {
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
        if (request.isPreview()) {
            if (!renderPreview())
                m_renderWindow->close();
        }
        else {
            if (!render())
                m_renderWindow->close();
        }
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

bool Crossaver::renderPreview() {
    return render();
}
