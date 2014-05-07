#ifndef INTERFACE_H
#define INTERFACE_H

#include "CazanoveGulinoMartinMaupas-Window.h"

class Interface
{
    Window *_win_path;

    public:
        Interface();
        Interface(const Interface &i);
        virtual ~Interface();

        Interface& operator=(const Interface &i);

        void display();
        // Getters
        Window* get_window_path();

};

#endif // INTERFACE_H
