#ifndef _COLORS_H_COLORS
#define _COLORS_H_COLORS

#include <crossaver.h>

#include <SFML/Graphics/Color.hpp>

class Colors : public Crossaver {

    protected:
        virtual bool init();

        virtual bool render();

    private:
        sf::Color randomColor();

        sf::Color m_color;

};

#endif // _COLORS_H_COLORS
