#include <crossaver.h>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class SimpleText : public Crossaver {

    protected:
        virtual bool init();

        virtual bool render();

        virtual bool shutDown();

    private:
        void randomPosition();

        sf::Clock m_clock;
        sf::Text m_text;
        sf::Font m_font;
        sf::Vector2f* m_tPos;

};
