#include "CazanoveGulinoMartinMaupas-Interface.h"

Interface::Interface() : _win_path(new Window(80, 3))
{
    _win_path->set_caption(std::string("Nom du fichier"));
}

Interface::~Interface()
{
    delete _win_path;
}

Interface::Interface(const Interface &i) : _win_path(new Window(i._win_path->get_width(), i._win_path->get_height()))
{
}

Interface& Interface::operator=(const Interface &i)
{
    if (this == &i)
        return *this;

    _win_path = new Window(i._win_path->get_width(), i._win_path->get_height());
    return *this;
}

void Interface::display()
{
    _win_path->display();
}

Window* Interface::get_window_path()
{
    return _win_path;
}
