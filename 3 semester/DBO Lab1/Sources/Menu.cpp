#include "Menu.h"

const string MAIN_MENU_OPTIONS_TEXT = "----------------------------------------\n"
                                      "| \033[31m[0] – Exit\033[0m                           |\n| [1]"
                                      " – New director                   |\n| [2] – Find director                  |\n| [3]"
                                      " – Delete director                |\n| [4] – Edit director                  |\n| [5]"
                                      " – New movie                      |\n| [6] – Find movie                     |\n| [7]"
                                      " – Delete movie                   |\n| [8] – Edit movie                     |\n| [9]"
                                      " – How many directors?            |\n| [10] – How many movies?              |\n| [11]"
                                      " – Count movies for the director |\n"
                                      "----------------------------------------\n";
const string MAIN_MENU_WRONG_INPUT = "Please type value between 0 and 4";

const string DIRECTOR_ID_REQUEST_TEXT = "Type id of a director";

const string DIRECTOR_NEW_ID_REQUEST_TEXT = "Type new id of a director";

const string NEW_DIRECTOR_NAME_REQUEST_TEXT = "Type name of a new director";
const string DIRECTOR_NEW_NAME_REQUEST_TEXT = "Type a new name for the director";

const string NEW_DIRECTOR_SURNAME_REQUEST_TEXT = "Type surname of a new director";
const string DIRECTOR_NEW_SURNAME_REQUEST_TEXT = "Type new surname for the director";

const string DIRECTOR_ID_IS_ALREADY_USED_TEXT = "Sorry this id is already occupied";

const string DIRECTOR_SUCCESSFULLY_ADDED_TEXT = "Successfully added director";
const string DIRECTOR_SUCCESSFULLY_DELETED_TEXT = "Successfully deleted director";

const string DIRECTOR_SELECT_FIELD_TO_UPDATE = "(0) stop updating\n(1) name\n(2) surname\n(3) id";

const string DIRECTOR_SUCCESSFULLY_UPDATED_TEXT = "Director was successfully updated";

const string MOVIE_ID_REQUEST_TEXT = "Please type id of a movie";

const string NEW_MOVIE_ID_REQUEST_TEXT = "Type an id of a new movie";
const string NEW_MOVIE_DIRECTOR_ID_REQUEST_TEXT = "Type an id of a director of new movie";
const string NEW_MOVIE_TITLE_REQUEST_TEXT = "Type a title of this movie";
const string NEW_MOVIE_RATING_REQUEST_TEXT = "Type a rating in this movie";
const string MOVIE_SUCCESSFULLY_ADDED_TEXT = "Movie was successfully added";

const string MOVIE_SUCCESSFULLY_DELETED_TEXT = "Movie was successfully deleted";

const string MOVIE_SELECT_FIELDS_TO_UPDATE_TEXT = "(0) stop updating\n(1) title\n(2) rating\n(3) id\n(4) director id";
const string MOVIE_NEW_DIRECTOR_ID_REQUEST_TEXT = "Type a new director id of a movie";
const string MOVIE_NEW_ID_REQUEST_TEXT = "Type a new id of a movie";
const string MOVIE_NEW_RATING_REQUEST_TEXT = "Type new rating of a movie";
const string MOVIE_NEW_TITLE_REQUEST_TEXT = "Type a new title of a movie";

const string ALL_DIRECTORS_COUNT_RESULT_TEXT = "Directors count: ";
const string ALL_MOVIES_COUNT_RESULT_TEXT = "Movies count: ";
const string DIRECTORS_MOVIES_COUNT_RESULT_TEXT = "Specified director's movies count:";

int readInt(const string& text)
{
	int value;
	cout << text << endl;
	cin >> value;
	return value;
}

char* readString(const string& text)
{
	char* string = new char[STRING_SIZE];
	cout << text << endl;
	cin >> string;
	return string;
}

void addDirectorMenu()
{
	int id;
	while (true)
    {
		id = readInt(DIRECTOR_ID_REQUEST_TEXT);
		
		if (existsDirector(id))
        {
			cout << DIRECTOR_ID_IS_ALREADY_USED_TEXT << endl;
			continue;
		}

		break;
	}

	char* name = readString(NEW_DIRECTOR_NAME_REQUEST_TEXT);
	char* surname = readString(NEW_DIRECTOR_SURNAME_REQUEST_TEXT);

	int error = 0;
	insertDirector(Directors(id, name, surname), error);

	if (error)
    {
		printError(error);
		error = 0;
		return;
	}
	cout << DIRECTOR_SUCCESSFULLY_ADDED_TEXT << endl;
}

void getDirectorMenu()
{
	int id = readInt(DIRECTOR_ID_REQUEST_TEXT);

	int error = 0;
	Directors director = getDirector(id, error);
	
	if (error)
    {
		printError(error);
		error = 0;
		return;
	}
	cout << director.toString() << endl;
}

void removeDirectorMenu()
{
	int id = readInt(DIRECTOR_ID_REQUEST_TEXT), error = 0;
	removeDirector(id, error);
	if (error)
    {
		printError(error);
		error = 0;
		return;
	}
	cout << DIRECTOR_SUCCESSFULLY_DELETED_TEXT << endl;
}

void updateMovieName(Directors& director)
{
	char* name = readString(DIRECTOR_NEW_NAME_REQUEST_TEXT);
	director.setName(name);
}

void updateMovieSurname(Directors& director)
{
	char* surname = readString(DIRECTOR_NEW_SURNAME_REQUEST_TEXT);
	director.setSurname(surname);
}

void updateMovieId(Directors& director)
{
	int id = readInt(DIRECTOR_NEW_ID_REQUEST_TEXT);
    director.setId(id);
}

void updateDirectorFields(Directors& director)
{
	int option;
	do
    {
		option = readInt(DIRECTOR_SELECT_FIELD_TO_UPDATE);
		switch (option)
        {
		case 0:
			break;
		case 1:
			updateMovieName(director);
			break;
		case 2:
			updateMovieSurname(director);
			break;
		case 3:
			updateMovieId(director);
			break;
        default:
            break;
		}
	} while (option != 0);
}

void updateDirectorMenu()
{
	int id = readInt(DIRECTOR_ID_REQUEST_TEXT), error = 0;
	Directors director = getDirector(id, error);

	if (error)
    {
		printError(error);
		error = 0;
		return;
	}

	updateDirectorFields(director);

	updateDirector(director, id, error);

	if (error)
    {
		printError(error);
		error = 0;
		return;
	}
	
	cout << DIRECTOR_SUCCESSFULLY_UPDATED_TEXT << endl;
}

void addMovieMenu()
{
	int id = readInt(NEW_MOVIE_ID_REQUEST_TEXT);
	int directorId = readInt(NEW_MOVIE_DIRECTOR_ID_REQUEST_TEXT);
	char* title = readString(NEW_MOVIE_TITLE_REQUEST_TEXT);
	int pagesNumber = readInt(NEW_MOVIE_RATING_REQUEST_TEXT);

	int error = 0;
	insertMovie(Movies(id, directorId, title, pagesNumber), error);
	
	if (error)
    {
		printError(error);
		error = 0;
		return;
	}

	cout << MOVIE_SUCCESSFULLY_ADDED_TEXT << endl;
}

void getMovieMenu()
{
	int directorId = readInt(DIRECTOR_ID_REQUEST_TEXT);
	int movieId = readInt(MOVIE_ID_REQUEST_TEXT);
		
	int error = 0;
	Movies movie = getMovie(directorId, movieId, error);
	if (error)
    {
		printError(error);
		error = 0;
		return;
	}

	Directors director = getDirector(directorId, error);
	if (error)
    {
		printError(error);
		error = 0;
		return;
	}

	cout << director.toString() << endl;
	cout << movie.toString() << endl;
}

void removeMovieMenu()
{
	int directorId = readInt(DIRECTOR_ID_REQUEST_TEXT);
	int movieId = readInt(MOVIE_ID_REQUEST_TEXT);
	
	int error = 0;
	removeMovie(directorId, movieId, error);
	if (error)
    {
		printError(error);
		error = 0;
		return;
	}
	cout << MOVIE_SUCCESSFULLY_DELETED_TEXT << endl;
}

void updateMovieTitle(Movies &movie)
{
	char* title = readString(MOVIE_NEW_TITLE_REQUEST_TEXT);
	movie.setTitle(title);
}

void updateMovieRating(Movies &movie)
{
	int rating = readInt(MOVIE_NEW_RATING_REQUEST_TEXT);
	movie.setRating(rating);
}

void updateMovieId(Movies& movie)
{
	int id = readInt(MOVIE_NEW_ID_REQUEST_TEXT);
	movie.setId(id);
}

void updateMovieDirectorId(Movies& movie)
{
	int directorId = readInt(MOVIE_NEW_DIRECTOR_ID_REQUEST_TEXT);
	movie.setDirectorId(directorId);
}

void updateMovieFields(Movies& movie)
{
	int options;
	do
    {
		options = readInt(MOVIE_SELECT_FIELDS_TO_UPDATE_TEXT);
		switch (options)
        {
			case 1:
				updateMovieTitle(movie);
				break;
			case 2:
				updateMovieRating(movie);
				break;
			case 3:
				updateMovieId(movie);
				break;
			case 4:
				updateMovieDirectorId(movie);
				break;
            default:
                break;
		}
	} while (options != 0);
}

void updateMovieMenu()
{
	int directorId = readInt(DIRECTOR_ID_REQUEST_TEXT);
	int movieId = readInt(MOVIE_ID_REQUEST_TEXT);

	int error = 0;
	Movies movie = getMovie(directorId, movieId, error);
	if (error)
    {
		printError(error);
		error = 0;
		return;
	}
	updateMovieFields(movie);
	updateMovie(movie, directorId, movieId, error);
}

void countAllDirectorsMenu()
{
	cout << ALL_DIRECTORS_COUNT_RESULT_TEXT << countAllDirectors() << endl;
}

void coutAllMoviesMenu()
{
	cout << ALL_MOVIES_COUNT_RESULT_TEXT << countAllMovies() << endl;
}

void countAllMoviesForDirectorMenu()
{
	int directorId = readInt(DIRECTOR_ID_REQUEST_TEXT), error = 0;
	long count = countMoviesForDirector(directorId, error);
	if (error)
    {
		printError(error);
		return;
	}
	cout << DIRECTORS_MOVIES_COUNT_RESULT_TEXT << count << endl;
}

void start()
{
	int option;
	do
    {
        cout << "\n~~~~~~~~~~~~~~~~  MENU  ~~~~~~~~~~~~~~~~\n";
		option = readInt(MAIN_MENU_OPTIONS_TEXT);
		switch (option)
		{
		case 0:
			break;
		case 1:
			addDirectorMenu();
			break;
		case 2:
			getDirectorMenu();
			break;
		case 3:
			removeDirectorMenu();
			break;
		case 4:
			updateDirectorMenu();
			break;
		case 5:
			addMovieMenu();
			break;
		case 6:
			getMovieMenu();
			break;
		case 7:
			removeMovieMenu();
			break;
		case 8:
			updateMovieMenu();
			break;
		case 9:
			countAllDirectorsMenu();
			break;
		case 10:
			coutAllMoviesMenu();
			break;
		case 11:
			countAllMoviesForDirectorMenu();
			break;
		default:
			cout << MAIN_MENU_WRONG_INPUT << endl;
			break;
		}
	} while (option != 0);
}