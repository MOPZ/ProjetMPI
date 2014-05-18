#include "CazanoveGulinoMartinMaupas-Automate.h"

using namespace std;

bool operator==(const State& s1, const State& s2)
{
    if (!(s1 < s2) and !(s2 < s1))
        return true;
    return false;
}

ostream& operator<<(ostream &os, const State& states)
{
    for (State::iterator it = states.begin(); it != states.end(); it++)
    {
        if (it != states.begin())
            os << ",";
        os << *it;
    }
    return os;
}

bool operator==(const t_transition& t1, const t_transition& t2)
{
    if (t1.b == t2.b && t1.e == t2.e && t1.c == t2.c)
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

void Automate::add_state(State states, bool in, bool out)
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

void Automate::add_input(State &states)
{
    _input.insert(states);
}

void Automate::add_input(state_type state)
{
    State s;
    s.insert(state);
    add_input(s);
}

void Automate::add_output(State &states)
{
    _output.insert(states);
}

void Automate::add_output(state_type state)
{
    State s;
    s.insert(state);
    add_output(s);
}

void Automate::add_transition(State b, State e, char c)
{
    t_transition t = {b, e, c};
    for (Transitions::iterator it = _transitions[b].begin(); it != _transitions[b].end(); it++)
    {
        if (*it == t)
            return;
    }
    _transitions[b].push_back(t);
    add_state(e);
}

void Automate::remove_transition(State &b, State &e, char c)
{
    t_transition t = {b, e, c};
    Transitions::iterator it = find(_transitions[b].begin(), _transitions[b].end(), t);

    _transitions[b].erase(it);
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
        // it->second = Transitions
        gotoxy(x, y);
        cout << it->first << ":";
        // it2 = t_transition
        for (Transitions::const_iterator it2 = it->second.begin(); it2 != it->second.end(); it2++)
        {
            if (it2 != it->second.begin())
                cout << ",";
            cout << " " << it2->c << " " << it2->e;
        }
        x = xi;
        y++;
    }
}

bool Automate::is_standard() const
{
    // Check nombre d'états initiaux
    if (_input.size() > 1)
    {
        cout << "Non-standard: possede plus d'un etat initial." << endl;
        return false;
    }
    // Check transitions vers état inital
    for (map<State, Transitions>::const_iterator it = _transitions.begin(); it != _transitions.end(); it++)
    {
        for (Transitions::const_iterator it2 = it->second.begin(); it2 != it->second.end(); it2++)
        {
            if (it2->e == (*_input.begin()))
            {
                cout << "Non-standard: " << it2->b << it2->c << it2->e << " mene vers un etat initial." << endl;
                return false;
            }
        }
    }
    return true;
}

void Automate::make_it_standard()
{
    if (!this->is_standard())
    {
        State state;
        state.insert("i");
        this->add_state(state);

        Transitions to_add;
        for (map<State, Transitions>::iterator it = _transitions.begin(); it != _transitions.end(); it++)
        {
            if (_input.find(it->first) != _input.end())
            {
                for (Transitions::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++)
                {
                    to_add.push_back(*it2);
                }
            }
        }
        for (Transitions::iterator it = to_add.begin(); it != to_add.end(); it++)
        {
            this->add_transition(state, it->e, it->c);
            this->remove_transition(it->b, it->e, it->c);
        }
    }
    cout << "L'automate est maintenant standard." << endl;
}


