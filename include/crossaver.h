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
        int run();

    protected:
        // Inits the structures used in the rendering.
        virtual bool init();

        // Frees the structures used in the rendering.
        virtual bool shutDown();

        // Draws one frame of the screensaver
        virtual bool render() = 0;

        // Draws one frame of the screensaver, for the preview window
        virtual bool renderPreview();

        // pointer to a SFML window
        sf::RenderWindow* m_renderWindow;

};

#endif // _CROSSAVER_H_CROSSAVER
