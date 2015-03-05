#include <crossaver.h>

Crossaver::Crossaver() : m_renderWindow(NULL) {}

Crossaver::~Crossaver() {
    if (m_renderWindow)
        delete m_renderWindow;
}

int Crossaver::run() {
    return 0;
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
