#include <iostream>
#include <fstream>
#include <string>
/* Conversion (c++11) */
#include <iomanip>
#include <locale>
#include <sstream>

#include "CazanoveGulinoMartinMaupas-Loader.h"
#include "conio.h"

using namespace std;

Loader::Loader() : _files()
{
}

Loader::~Loader()
{
}

bool Loader::test_path(const std::string &path) const
{
    FILE *file = NULL;
    bool test;

    file = fopen(path.c_str(), "r");
    test = file;
    fclose(file);
    return test;
}

bool Loader::load(const std::string &path)
{
    ifstream file(path, ios::in);

    gotoxy(1, 10);
    if (file)
    {
        _files[path] = new Automate;
        string line;

        /* Language */
        getline(file, line);
        if (line != "<language>")
            return false;
        else
        {
            do
            {
                getline(file, line);
                if (line != "</language>")
                {
                    _files[path]->add_to_language(line.c_str()[1]);
                }
            }while (line != "</language>");
        }
        /* States */
        getline(file, line);
        if (line != "<states>")
            return false;
        else
        {
            getline(file, line);
            int states = strtol(line.c_str(), 0, 10);
            for (int i = 0; i < states; i++)
            {
                ostringstream convert;
                convert << i+1;
                _files[path]->add_state(convert.str());
            }
            getline(file, line);
            if (line != "</states>")
                return false;
        }
        /* Input */
        getline(file, line);
        if (line != "<input>")
            return false;
        else
        {
            do
            {
                getline(file, line);
                if (line != "</input>")
                {
                    _files[path]->add_input(line);
                }
            }while (line != "</input>");
        }
        /* Output */
        getline(file, line);
        if (line != "<output>")
            return false;
        else
        {
            do
            {
                getline(file, line);
                if (line != "</output>")
                {
                    _files[path]->add_output(line);
                }
            }while (line != "</output>");
        }
        /* Transitions */
        getline(file, line);
        if (line != "<transition>")
            return false;
        else
        {
            do
            {
                getline(file, line);
                string state1, state2;
                char c;
                if (line != "</transition>")
                {
                    unsigned int i;
                    for (i = 0; line[i] >= '0' and line [i] <= '9'; i++)
                        state1.push_back(line[i]);
                    c = line[i];
                    for (i = i+1; i < line.size(); i++)
                        state2.push_back(line[i]);
                    _files[path]->add_transition(state1, state2, c);
                }
            }while (line != "</transition>");
        }
    }
    return true;
}

void Loader::show_load_error() const
{
    gotoxy(1, 5);
    cout << "Le chargement du fichier n'a pas reussi. Veuillez verifier que celui-ci n'est pas corrompu et que sa syntaxe suit celle-ci-dessous :\n\n";
    textcolor(RED);
    cout << "<language>\n";
    textcolor(LIGHTGRAY);
    cout << "a\nb\n";
    textcolor(RED);
    cout << "</language>\n<states>\n";
    textcolor(LIGHTGRAY);
    cout << "4\n";
    textcolor(RED);
    cout << "</states>\n<input>\n";
    textcolor(LIGHTGRAY);
    cout << "1\n3\n";
    textcolor(RED);
    cout << "</input>\n<output>\n";
    textcolor(LIGHTGRAY);
    cout << "2\n4\n";
    textcolor(RED);
    cout << "</output>\n<transition>\n";
    textcolor(LIGHTGRAY);
    cout << "1a2\n3b4\n";
    textcolor(RED);
    cout << "</transition>\n" << endl;
    textcolor(LIGHTGRAY);
}

