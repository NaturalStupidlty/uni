#ifndef INCLUDED_Movies_H
#define INCLUDED_Movies_H

#include "Constants.h"
#include <vector>
#include <string>

struct Movies
{
private:
	int id{};
	int directorId{};
	char* title = new char[STRING_SIZE];
	int rating = 0;
	long int nextMovie = -1;
	long int previousMovie = -1;
	int state{};

public:
	void setId(int newId);
	
	int getId() const;
	
	void setDirectorId(int newDirectorId);
	
	int getDirectorId() const;
	
	void setTitle(char* newTitle);
	
	char* getTitle();

	void setRating(int newRating);

	int getRating() const;
	
	void setNextMovie(long int newNextMovie);

	long int getNextMovie() const;

    void setPreviousMovie(long int newPreviousMovie);

	long int getPreviousMovie() const;

	void setState(int newState);

	int getState() const;

	std::string toString();

	Movies(int id,
         int directorId,
         const char* title,
         int rating,
         long previousMovie = END_MARK,
         long nextMovie = END_MARK,
         int state = MOVIE_ACTIVE_STATE);

	Movies()= default;
};


#endif  // INCLUDED_Movies_H
