#ifndef _CROSSAVER_H_CROSSAVER
#define _CROSSAVER_H_CROSSAVER

#include <SFML/Graphics/RenderWindow.hpp>

class Crossaver {

    public:
        // The constructor
        Crossaver();

        // The destructor
        virtual ~Crossaver();

        // Called in the main function.
        // Returns the value the main program must return.
        int run(int argc, char** argv);

    protected:
        // Inits the structures used in the rendering.
        virtual bool init();

        // Frees the structures used in the rendering.
        virtual bool shutDown();

        // Draws one frame of the screensaver
        virtual bool render() = 0;

        // Returns true if the screensaver is in preview mode
        bool isPreview();

        // pointer to a SFML window
        sf::RenderWindow* m_renderWindow;

    private:
        // true if the screensaver has to render itself in preview mode
        bool m_isPreview;

};

#endif // _CROSSAVER_H_CROSSAVER
