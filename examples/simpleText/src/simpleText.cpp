#include "simpleText.h"

#include <cstdlib>
#include <ctime>

bool SimpleText::init() {
    srand(time(NULL));
    m_font.loadFromFile("DejaVuSans.ttf");
    m_text.setFont(m_font);
    if (isPreview()) {
        m_text.setString("Example preview text");
        m_text.setCharacterSize(20);
    } else {
        m_text.setString("Example text");
        m_text.setCharacterSize(30);
    }
    m_text.setColor(sf::Color::Black);
    m_tPos = NULL;

    randomPosition();
    m_text.setPosition(*m_tPos);
    m_renderWindow->clear(sf::Color::White);
    m_renderWindow->draw(m_text);
    m_renderWindow->display();

    return true;
}

bool SimpleText::render() {
    if (m_clock.getElapsedTime().asSeconds() < 3) {
        return true;
    }

    randomPosition();
    m_text.setPosition(*m_tPos);
    m_renderWindow->clear(sf::Color::White);
    m_renderWindow->draw(m_text);
    m_renderWindow->display();

    m_clock.restart();

    return true;
}

bool SimpleText::shutDown() {
    if (m_tPos)
        delete m_tPos;
}

void SimpleText::randomPosition() {
    sf::Vector2u winSize(m_renderWindow->getSize());
    sf::FloatRect textSize(m_text.getLocalBounds());
    int x = rand() % (winSize.x - (int) textSize.width);
    int y = rand() % (winSize.y - (int) textSize.height);
    if (m_tPos)
        delete m_tPos;
    m_tPos = new sf::Vector2f(x, y);
}
