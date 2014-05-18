#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>

#include "conio.h"

typedef std::string state_type;
typedef std::set<state_type> State;

bool operator==(const State&, const State&);
std::ostream& operator<<(std::ostream &os, const State&);

struct t_transition
{
    State b; // begin
    State e; // end
    char c;
};

<<<<<<< HEAD
bool operator==(const t_transition&, const t_transition&);

typedef std::vector<t_transition> Transitions;
=======
<<<<<<< HEAD
bool operator==(const t_transition&, const t_transition&);

typedef std::vector<t_transition> Transitions;
=======
typedef std::list<t_transition> Transitions;
>>>>>>> 064adb67c5f1f1e93190d6f71e7f698d1ae95190
>>>>>>> f5c0a5754852fda70a31ad9f858d57d70c218401

class Automate
{
    std::list<char> _language;
    std::map<State, Transitions> _transitions;
<<<<<<< HEAD
    std::set<State> _input, _output;
=======
<<<<<<< HEAD
    std::set<State> _input, _output;
=======
    std::list<State> _input, _output;
>>>>>>> 064adb67c5f1f1e93190d6f71e7f698d1ae95190
>>>>>>> f5c0a5754852fda70a31ad9f858d57d70c218401

    public:
        Automate();
        virtual ~Automate();
        Automate(const Automate& other);
        Automate& operator=(const Automate& other);

        /* Language */
        void set_language(const std::list<char> &);
        void add_to_language(char);

        /* States */
<<<<<<< HEAD
        void add_state(State states, bool in = false, bool out = false);
=======
<<<<<<< HEAD
        void add_state(State states, bool in = false, bool out = false);
=======
        void add_state(const State &states, bool in = false, bool out = false);
>>>>>>> 064adb67c5f1f1e93190d6f71e7f698d1ae95190
>>>>>>> f5c0a5754852fda70a31ad9f858d57d70c218401
        void add_state(state_type, bool in = false, bool out = false);
        void remove_state(const State &);
        void remove_state(state_type state);

        /* Initial and terminal */
<<<<<<< HEAD
        void add_input(State &states);
=======
<<<<<<< HEAD
        void add_input(State &states);
        void add_input(state_type);
        void add_output(State &states);
        void add_output(state_type);

        /* Transitions */
        void add_transition(State b, State e, char c = '\0');
        void add_transition(state_type b, state_type e, char c);
        void remove_transition(State &b, State &e, char c);
        void remove_transition(state_type &b, state_type &e, char c);

        /* Display */
        void display_transitions() const;

        /* Traitement */
        bool is_standard() const;
        void make_it_standard();
=======
        void add_input(const State &states);
>>>>>>> f5c0a5754852fda70a31ad9f858d57d70c218401
        void add_input(state_type);
        void add_output(State &states);
        void add_output(state_type);

        /* Transitions */
        void add_transition(State b, State e, char c = '\0');
        void add_transition(state_type b, state_type e, char c);
        void remove_transition(State &b, State &e, char c);
        void remove_transition(state_type &b, state_type &e, char c);

        /* Display */
        void display_transitions() const;
<<<<<<< HEAD

        /* Traitement */
        bool is_standard() const;
        void make_it_standard();
=======
        static void display_state(const State &state)
        {
            for (State::iterator it = state.begin(); it != state.end(); it++)
            {
                if (it != state.begin())
                    std::cout << ",";
                std::cout << *it;
            }
        }
>>>>>>> 064adb67c5f1f1e93190d6f71e7f698d1ae95190
>>>>>>> f5c0a5754852fda70a31ad9f858d57d70c218401

    protected:
    private:
};

#endif // AUTOMATE_H
