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

typedef std::list<t_transition> Transitions;

class Automate
{
    std::list<char> _language;
    std::map<State, Transitions> _transitions;
    std::list<State> _input, _output;

    public:
        Automate();
        virtual ~Automate();
        Automate(const Automate& other);
        Automate& operator=(const Automate& other);

        /* Language */
        void set_language(const std::list<char> &);
        void add_to_language(char);

        /* States */
        void add_state(const State &states, bool in = false, bool out = false);
        void add_state(state_type, bool in = false, bool out = false);
        void remove_state(const State &);
        void remove_state(state_type state);

        /* Initial and terminal */
        void add_input(const State &states);
        void add_input(state_type);
        void add_output(const State &states);
        void add_output(state_type);

        /* Transitions */
        void add_transition(const State &b, const State &e, char c = '\0');
        void add_transition(state_type b, state_type e, char c);

        /* Display */
        void display_transitions() const;
        static void display_state(const State &state)
        {
            for (State::iterator it = state.begin(); it != state.end(); it++)
            {
                if (it != state.begin())
                    std::cout << ",";
                std::cout << *it;
            }
        }

    protected:
    private:
};

#endif // AUTOMATE_H
