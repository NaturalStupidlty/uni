#include "Directors.h"

char *Directors::getName()
{
    return name;
}

char *Directors::getSurname()
{
    return surname;
}

int Directors::getId() const
{
    return id;
}

void Directors::setName(char *newName)
{
    memcpy(name, newName, STRING_SIZE);
}

void Directors::setSurname(char *newSurname)
{
    memcpy(surname, newSurname, STRING_SIZE);
}

void Directors::setId(int newId)
{
    id = newId;
}

void Directors::setState(int newState)
{
    state = newState;
}

int Directors::getState() const
{
    return state;
}

void Directors::setFirstMovie(long newFirstMovie)
{
    firstMovie = newFirstMovie;
}

long int Directors::getFirstMovie() const
{
    return firstMovie;
}

Directors::Directors(int id,
                     const char *name,
                     const char *surname,
                     int state,
                     long firstMovie)
{
    this->id = id;
    memcpy(this->name, name, STRING_SIZE);
    memcpy(this->surname, surname, STRING_SIZE);
    this->state = state;
    this->firstMovie = firstMovie;
}

std::string Directors::toString()
{
    return std::to_string(id) + "ID: " + name + " " + surname;
}
