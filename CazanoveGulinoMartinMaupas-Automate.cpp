#include "CazanoveGulinoMartinMaupas-Automate.h"

using namespace std;

bool operator==(const State& s1, const State& s2)
{
    if (!(s1 < s2) and !(s2 < s1))
        return true;
    return false;
}

Automate::Automate() : _language(), _transitions(), _input(), _output()
{
    //ctor
}

Automate::~Automate()
{
    //dtor
}

Automate::Automate(const Automate &a) : _language(a._language), _transitions(a._transitions), _input(a._input), _output(a._output)
{
}

Automate& Automate::operator=(const Automate& rhs)
{
    if (this == &rhs)
        return *this; // handle self assignment

    _language = rhs._language;
    _transitions = rhs._transitions;
    _input = rhs._input;
    _output = rhs._output;
    return *this;
}

void Automate::add_to_language(char c)
{
    for (std::list<char>::iterator it = _language.begin(); it != _language.end(); it++)
    {
        if (*it == c)
            return;
    }
    _language.push_back(c);
}

void Automate::add_state(const State &states, bool in, bool out)
{
    Transitions old = _transitions[states];
    _transitions[states] = old;
}

void Automate::add_state(state_type state, bool in, bool out)
{
    State s;
    s.insert(state);
    add_state(s);
}

void Automate::remove_state(const State &states)
{
    _transitions.erase(states);
}

void Automate::remove_state(state_type state)
{
    State s;
    s.insert(state);
    remove_state(s);
}

void Automate::add_input(const State &states)
{
    _input.push_back(states);
}

void Automate::add_input(state_type state)
{
    State s;
    s.insert(state);
    add_input(s);
}

void Automate::add_output(const State &states)
{
    _output.push_back(states);
}

void Automate::add_output(state_type state)
{
    State s;
    s.insert(state);
    add_output(s);
}

void Automate::add_transition(const State &b, const State &e, char c)
{
    if (find(_language.begin(), _language.end(), c) != _language.end())
    {
        t_transition t = {b, e, c};
        _transitions[b].push_back(t);
        //_transitions[b].insert(t);
    }
    add_state(e);
}

void Automate::add_transition(state_type b, state_type e, char c)
{
    State s, p;
    s.insert(b);
    p.insert(e);
    add_transition(s, p, c);
}

void Automate::display_transitions() const
{
    unsigned int xi = wherex(), y = wherey();
    map<State, Transitions>::const_iterator it;
    unsigned int x = xi;

    // it = pair<State, Transitions>
    for (it = _transitions.begin(); it != _transitions.end(); it++)
    {
        // it->first = State
        gotoxy(x, y);
        display_state(it->first);
        // it->second = Transitions
        for (Transitions::const_iterator it2 = it->second.begin(); it2 != it->second.end(); it2++)
        {
            gotoxy(x+10, y);
            cout << it2->c;
            display_state(it2->e);
            x += 10;
        }
        x = xi;
        y++;
    }
}


