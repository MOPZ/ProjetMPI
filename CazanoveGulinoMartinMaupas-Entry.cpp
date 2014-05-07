#include "CazanoveGulinoMartinMaupas-Entry.h"

using namespace std;

Entry::Entry(string default_text, unsigned int size) : _text(default_text), _max_size(size)
{
    //ctor
}

Entry::~Entry()
{
    //dtor
}

void Entry::type()
{
    int key;

    //textcolor(LIGHTGRAY);
    cout << _text;
    do
    {
        key = getch();
        if (key != ASCII_RETURN)
        {
            if (key == ASCII_BACKSPACE)
            {
                if (_text.size() > 0)
                {
                    gotoxy(wherex()-1, wherey());
                    cout << " ";
                    gotoxy(wherex()-1, wherey());
                    _text.resize(_text.size()-1);
                }
            }
            else
            {
                if (_text.size() < _max_size)
                {
                    cout << (char)(key);
                    _text.push_back((char)key);
                }
            }
        }

    }while (key != ASCII_RETURN);
    //textcolor(LIGHTGRAY);
}

const string& Entry::get_text()
{
    return _text;
}
