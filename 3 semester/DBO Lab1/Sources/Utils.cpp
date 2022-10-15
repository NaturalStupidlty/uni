#include "Utils.h"

long int getLastAddressInFile(FILE* file)
{
	fseek(file, 0, SEEK_END);
	return ftell(file);
}

void writeDirector(Directors& director, FILE* file)
{
	int id = director.getId();
	int state = director.getState();
	long int firstMovie = director.getFirstMovie();
	fwrite(&id, sizeof(int), 1, file);
	fwrite(director.getName(), sizeof(char), STRING_SIZE, file);
	fwrite(director.getSurname(), sizeof(char), STRING_SIZE, file);
	fwrite(&state, sizeof(int), 1, file);
	fwrite(&firstMovie, sizeof(long int), 1, file);
}

void writeDirector(Directors& director, long int address, FILE* file)
{
	fseek(file, address, SEEK_SET);
	writeDirector(director, file);
}

void writeMovie(Movies& movie, FILE* file)
{
	int id = movie.getId();
	int directorId = movie.getDirectorId();
	int rating = movie.getRating();
	long int previousMovie = movie.getPreviousMovie();
	long int nextMovie = movie.getNextMovie();
	fwrite(&id, sizeof(int), 1, file);
	fwrite(&directorId, sizeof(int), 1, file);
	fwrite(movie.getTitle(), sizeof(char), STRING_SIZE, file);
	fwrite(&rating, sizeof(int), 1, file);
	fwrite(&previousMovie, sizeof(long int), 1, file);
	fwrite(&nextMovie, sizeof(long int), 1, file);
}

void writeMovie(Movies& movie, long int address, FILE* file)
{
	fseek(file, address, SEEK_SET);
	writeMovie(movie, file);
}

Directors readDirector(FILE* file)
{
	char* name = new char[STRING_SIZE];
	char* surname = new char[STRING_SIZE];
	int id;
	int state;
	long int firstMovie;
	fread(&id, sizeof(int), 1, file);
	fread(name, sizeof(char), STRING_SIZE, file);
	fread(surname, sizeof(char), STRING_SIZE, file);
	fread(&state, sizeof(int), 1, file);
	fread(&firstMovie, sizeof(long int), 1, file);
	return {id, name, surname, state, firstMovie};
}

Directors readDirector(FILE* file, long int address)
{
	fseek(file, address, SEEK_SET);
	return readDirector(file);
}

Movies readMovie(FILE* file)
{
	int id;
	int directorId;
	char* title = new char[STRING_SIZE];
	int rating;
	long int previousMovie;
	long int nextMovie;
	fread(&id, sizeof(int), 1, file);
	fread(&directorId, sizeof(int), 1, file);
	fread(title, sizeof(char), STRING_SIZE, file);
	fread(&rating, sizeof(int), 1, file);
	fread(&previousMovie, sizeof(long int), 1, file);
	fread(&nextMovie, sizeof(long int), 1, file);
	return {id, directorId, title, rating, previousMovie, nextMovie};
}

Movies readMovie(FILE* file, long int address)
{
	fseek(file, address, SEEK_SET);
	return readMovie(file);
}

bool fileEmpty(char* path)
{
	FILE* file = fopen(path, "rb");

	if (!file) return true;

	fseek(file, 0, SEEK_END);
	long int address = ftell(file);
	fclose(file);

	return address == 0;
}

bool fileEmpty(FILE* file)
{
	fseek(file, 0, SEEK_END);
	long int address = ftell(file);
	fseek(file, 0, SEEK_SET);
	return address == 0;
}