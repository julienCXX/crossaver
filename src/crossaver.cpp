#include <crossaver.h>

#include <SFML/Window/Event.hpp>

#include "request.h"

Crossaver::Crossaver() : m_renderWindow(NULL), m_isPreview(false) {}

Crossaver::~Crossaver() {
    if (m_renderWindow)
        delete m_renderWindow;
}

int Crossaver::run() {
    Request request;
    sf::Event toProcess;
    int mouseX = -1; int mouseY = -1;

    m_isPreview = request.isPreview();
    if (m_isPreview) {
        m_renderWindow = new sf::RenderWindow(request.getHandle());
    } else {
        m_renderWindow = new sf::RenderWindow(sf::VideoMode(800, 600, 32),
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
            if (!m_isPreview) {
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
