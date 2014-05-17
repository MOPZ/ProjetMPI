#ifndef ENTRY_H
#define ENTRY_H

#include <iostream>
#include <string>
#include "conio.h"

/* Codes ASCII touches */
#define ASCII_RETURN 13
#define ASCII_ESCAPE 27
#define ASCII_BACKSPACE 8

class Entry
{
    std::string _text;
    unsigned int _max_size;

    public:
        Entry(std::string default_text = "", unsigned int size = 128);
        virtual ~Entry();

        void type();
        std::string get_text();

    private:
};

#endif // ENTRY_H
