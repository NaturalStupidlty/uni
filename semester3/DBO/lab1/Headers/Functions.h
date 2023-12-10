#ifndef INCLUDED_Functions_H
#define INCLUDED_Functions_H

#include "Directors.h"
#include "Utils.h"
#include "Movies.h"
#include <iostream>
#include <cstdio>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;

void prepare(char* directorsFilePath,
           char* freeSpacesAddressesFilePath,
           char* indexFilePath,
           char* moviesFilePath,
           int& error);

void close(int &error);

bool existsDirector(int id);

void insertDirector(Directors director, int &error);

void insertMovie(Movies movie, int &error);

void removeDirector(int id, int &error);

void removeMovie(int movieId, int directorId, int &error);

void updateDirector(Directors director, int id,  int &error);

void updateMovie(Movies movie, int directorId, int movieId, int& error);

Directors getDirector(int id, int &error);

Movies getMovie(int movieId, int id, int& error);

long countAllDirectors();

long countAllMovies();

long countMoviesForDirector(int directorId, int& error);

#endif // INCLUDED_Functions_H