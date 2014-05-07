#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <string>

#include "conio.h"

enum Window_Type
{
    WINDOW_SIMPLE, WINDOW_DOUBLE
};

class Window
{
    unsigned int _width, _height, _x, _y;
    Window_Type _type;
    std::string _caption;

    public:
        Window();
        Window(unsigned int width, unsigned int height, unsigned int x = 1, unsigned int y = 1,  Window_Type type = WINDOW_SIMPLE);
        virtual ~Window();

        void display() const;

        // Getters
        std::string get_caption() const;
        unsigned int get_width() const;
        unsigned int get_height() const;
        unsigned int get_x() const;
        unsigned int get_y() const;

        // Setters
        void set_caption(std::string &caption);
        void set_caption(std::string caption);
        void set_type(Window_Type type);
        void set_pos(unsigned int x, unsigned int y);
        void set_size(unsigned int width, unsigned int height);

    private:
        inline void display_caption() const;
        inline void display_simple() const;
        inline void display_double() const;
};

#endif // WINDOW_H
