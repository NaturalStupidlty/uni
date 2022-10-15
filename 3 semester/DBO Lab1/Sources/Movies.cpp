#include "Movies.h"

void Movies::setId(int newId)
{
    id = newId;
}

int Movies::getId() const
{
    return id;
}

void Movies::setDirectorId(int newDirectorId)
{
    directorId = newDirectorId;
}

int Movies::getDirectorId() const
{
    return directorId;
}

void Movies::setTitle(char* newTitle)
{
    memcpy(title, newTitle, STRING_SIZE);
}

char* Movies::getTitle()
{
    return title;
}

void Movies::setRating(int newRating)
{
    rating = newRating;
}

int Movies::getRating() const
{
    return rating;
}

void Movies::setNextMovie(long int newNextMovie)
{
    nextMovie = newNextMovie;
}

long int Movies::getNextMovie() const
{
    return nextMovie;
}

void Movies::setPreviousMovie(long int newPreviousMovie)
{
    previousMovie= newPreviousMovie;
}

long int Movies::getPreviousMovie() const
{
    return previousMovie;
}

void Movies::setState(int newState)
{
    state = newState;
}

int Movies::getState() const
{
    return state;
}

std::string Movies::toString()
{
    return std::to_string(id) + "ID: "  + std::to_string(directorId) + "Director ID:  " + title + " Rating: " + std::to_string(rating) + "/10";
}

Movies::Movies(int id,
     int directorId,
     const char* title,
     int rating,
     long previousMovie,
     long nextMovie,
     int state)
{
    this->id = id;
    this->directorId = directorId;
    memcpy(this->title, title, STRING_SIZE);
    this->rating = rating;
    this->nextMovie = nextMovie;
    this->state = state;
    this->previousMovie = previousMovie;
}