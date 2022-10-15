#ifndef INCLUDED_Directors_H
#define INCLUDED_Directors_H

#include "Constants.h"
#include <string>
#include <vector>
#include <cstdlib>

struct Directors
{
private:
	int id = -1;
	char* name = new char[STRING_SIZE];
	char* surname = new char[STRING_SIZE];
	int state = DIRECTOR_ACTIVE_STATE;
	long int firstMovie{};

public:
	char* getName();

	char* getSurname();

	int getId() const;

	void setName(char* newName);

	void setSurname(char* newSurname);

	void setId(int newId);

	void setState(int newState);

	int getState() const;

	void setFirstMovie(long int newFirstMovie);

	long int getFirstMovie() const;

	Directors(int id,
              const char* name,
              const char* surname,
              int state = DIRECTOR_ACTIVE_STATE,
              long int firstMovie = END_MARK);

	std::string toString();

	Directors() = default;
};

#endif // INCLUDED_Directors_H
