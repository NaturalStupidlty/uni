#ifndef INCLUDED_Utils_H
#define INCLUDED_Utils_H

#include <iostream>
#include "Directors.h"
#include "Movies.h"
#include <vector>

long int getLastAddressInFile(FILE* file);

void writeDirector(Directors& director, FILE* file);

void writeDirector(Directors& director, long int address, FILE* file);

void writeMovie(Movies& movie, FILE* file);

void writeMovie(Movies& movie, long int address, FILE* file);

Directors readDirector(FILE* file);

Directors readDirector(FILE* file, long int address);

Movies readMovie(FILE* file);

Movies readMovie(FILE* file, long int address);

bool fileEmpty(char* path);

bool fileEmpty(FILE* file);

#endif // !INCLUDED_Utils_H