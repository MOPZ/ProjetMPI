#include "CazanoveGulinoMartinMaupas-Interface.h"
#include "CazanoveGulinoMartinMaupas-Entry.h"
#include "CazanoveGulinoMartinMaupas-Loader.h"
#include "CazanoveGulinoMartinMaupas-Automate.h"

#include <set>

using namespace std;

int main(int argc, char **argv)
{
    /* Interface display */
    Interface *interface = new Interface;
    interface->display();

    /* Loading file */
    Entry file_name("aut/CazanoveGulinoMartinMaupas-test1.txt", 78);
    Loader loader;
    bool exists;
    do
    {
        gotoxy(2, 2);
        file_name.type();
        exists = loader.test_path(file_name.get_text());
    }while (!exists);
    if (!loader.load(file_name.get_text())) // échec du chargement
    {
        loader.show_load_error();
    }

    /* Traitement */

    Automate *automate = loader.get(file_name.get_text());

    automate->display_transitions();

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> f5c0a5754852fda70a31ad9f858d57d70c218401
    gotoxy(1, 15);
    automate->make_it_standard();

    gotoxy(1, wherey()+1);
    automate->display_transitions();

<<<<<<< HEAD
=======
=======
>>>>>>> 064adb67c5f1f1e93190d6f71e7f698d1ae95190
>>>>>>> f5c0a5754852fda70a31ad9f858d57d70c218401
    return 0;
}
