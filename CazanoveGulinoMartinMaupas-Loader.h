#ifndef LOADER_H_INCLUDED
#define LOADER_H_INCLUDED

#include <string>
#include <map>

#include "CazanoveGulinoMartinMaupas-Automate.h"

class Loader
{
    std::map<std::string, Automate*> _files;

    public :
        Loader();
        ~Loader();

        Automate* get(std::string path);
        bool test_path(const std::string &path) const;
        bool load(const std::string &path);
        void show_load_error() const;

};

#endif // LOADER_H_INCLUDED
