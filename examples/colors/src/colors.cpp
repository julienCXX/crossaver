#include "colors.h"

#include <cstdlib>
#include <ctime>

bool Colors::init() {
    srand(time(NULL));

    m_color = randomColor();
    if (isPreview())
        m_renderWindow->setFramerateLimit(2);
    else
        m_renderWindow->setFramerateLimit(1);
    m_renderWindow->clear(m_color);
    m_renderWindow->display();

    return true;
}

bool Colors::render() {
    m_color = randomColor();
    m_renderWindow->clear(m_color);
    m_renderWindow->display();

    return true;
}

sf::Color Colors::randomColor() {
    sf::Uint8 r = rand() % 256;
    sf::Uint8 g = rand() % 256;
    sf::Uint8 b = rand() % 256;
    return sf::Color(r, g, b);
}
