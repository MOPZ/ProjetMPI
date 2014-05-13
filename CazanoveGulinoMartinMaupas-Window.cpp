#include "CazanoveGulinoMartinMaupas-Window.h"

Window::Window() : _width(80), _height(25), _x(1), _y(1), _type(WINDOW_SIMPLE), _caption("")
{
}

Window::Window(unsigned int width, unsigned int height, unsigned int x, unsigned int y, Window_Type type) : _width(width), _height(height), _x(x), _y(y), _type(type), _caption("")
{
}

Window::~Window()
{
    //dtor
}

void Window::display() const
{
    if (_type == WINDOW_DOUBLE)
        display_double();
    else
        display_simple();
    if (_caption.size() > 0)
        display_caption();
}

inline void Window::display_caption() const
{
    //textcolor(DARKGRAY);
    gotoxy(_x+1, _y);
    std::cout << _caption;
    //textcolor(LIGHTGRAY);
}

inline void Window::display_simple() const
{
    unsigned int i;
    if (_width < 2 || _height < 2)
        return;

    gotoxy(_x, _y);
    putchar((unsigned char)(218)); // haut gauche
    for (i = 1; i < _width-1; i++)
        putchar((unsigned char)(196)); // horizontal
    putchar((unsigned char)(191)); // haut droite
    for (i = 1; i < _height-1; i++)
    {
        gotoxy(_x, _y+i);
        putchar((unsigned char)(179)); // vertical
        gotoxy(_x+_width-1, _y+i);
        putchar((unsigned char)(179)); // vertical
    }
    gotoxy(_x, _y+_height-1);
    putchar((unsigned char)(192)); // bas gauche
    for (i = 1; i < _width-1; i++)
        putchar((unsigned char)(196)); // horizontal
    putchar((unsigned char)(217)); // bas droite
}

inline void Window::display_double() const
{
    unsigned int i;
    if (_width < 2 || _height < 2)
        return; // échec

    gotoxy(_x, _y);
    putchar((unsigned char)(201)); // haut gauche
    for (i = 1; i < _width-1; i++)
        putchar((unsigned char)(205)); // horizontal
    putchar((unsigned char)(187)); // haut droite
    for (i = 1; i < _height-1; i++)
    {
        gotoxy(_x, _y+i);
        putchar((unsigned char)(186)); // vertical
        gotoxy(_x+_width-1, _y+i);
        putchar((unsigned char)(186)); // vertical
    }
    gotoxy(_x, _y+_height-1);
    putchar((unsigned char)(200)); // bas gauche
    for (i = 1; i < _width-1; i++)
        putchar((unsigned char)(205)); // horizontal
    putchar((unsigned char)(188)); // bas droite
}

std::string Window::get_caption() const
{
    return _caption;
}

unsigned int Window::get_width() const
{
    return _width;
}

unsigned int Window::get_height() const
{
    return _height;
}

unsigned int Window::get_x() const
{
    return _x;
}

unsigned int Window::get_y() const
{
    return _y;
}

void Window::set_caption(std::string &caption)
{
    _caption = caption;
}

void Window::set_caption(std::string caption)
{
    _caption = caption;
}

void Window::set_type(Window_Type type)
{
    _type = type;
}

void Window::set_pos(unsigned int x, unsigned int y)
{
    _x = x;
    _y = y;
}

void Window::set_size(unsigned int width, unsigned int height)
{
    _width = width;
    _height = height;
}

