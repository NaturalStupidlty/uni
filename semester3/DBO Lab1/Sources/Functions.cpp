#include "Functions.h"
#include "Utils.h"

vector<pair<int, long int>> indexes;
vector <long int> garbage;
FILE* directorsF;
FILE* moviesF;
char* garbageAddresses;
char* indexAddresses;

int findDirectorInIndex(int id)
{
	int l = 0, r = (int)indexes.size() - 1, mid;
	while (r >= l)
    {
		mid = (l + r) / 2;
		if (indexes[mid].first == id)
        {
			return mid;
		}
		if (indexes[mid].first > id)
        {
			r = mid - 1;
		}
		else
        {
			l = mid + 1;
		}
	}
	return ABSENT_MARK;
}

long int findDirectorAddress(int id)
{
	int index = findDirectorInIndex(id);
	return index == ABSENT_MARK ? ABSENT_MARK : indexes[index].second;
}

void loadIndexes(int &error)
{
	FILE* file = fopen(indexAddresses, "wb+");

	if (!file)
    {
		error = CAN_NOT_LOAD_INDEX_FILE_ERROR_CODE;
		return;
	}
	if (!fileEmpty(file))
    {
		int id;
		long int position;

		fread(&id, sizeof(int), 1, file);
		fread(&position, sizeof(long int), 1, file);
		while (!feof(file))
        {
			indexes.emplace_back( id, position );
			fread(&id, sizeof(int), 1, file);
			fread(&position, sizeof(long int), 1, file);
		} 
	}
	fclose(file);
}

void writeIndexes(int& error)
{
	FILE* file = fopen(indexAddresses, "wb+");

	if (!file)
    {
		error = CAN_NOT_LOAD_INDEX_FILE_ERROR_CODE;
		return;
	}
	for (pair<int, long int>& item : indexes)
    {
		fwrite(&item.first, sizeof(int), 1, file);
		fwrite(&item.second, sizeof(long int), 1, file);
	}
	fclose(file);
}

void loadFreeSpaceAddresses(int& error)
{
	if (fileEmpty(garbageAddresses))
    {
        return;
    }

	FILE* file = fopen(garbageAddresses, "wb+");
	
	if (!file)
    {
		error = CAN_NOT_LOAD_FREE_SPACES_FILE_ERROR_CODE;
		return;
	}

	int freeSpace;
	do
    {
		fread(&freeSpace, sizeof(long int), 1, file);
		garbage.push_back(freeSpace);
	} while (!feof(file));

	fclose(file);
}

void writeFreeSpaceAddresses(int& error)
{
	FILE* file = fopen(garbageAddresses, "wb+");

	if (!file)
    {
		error = CAN_NOT_LOAD_FREE_SPACES_FILE_ERROR_CODE;
		return;
	}

	for (long int freeSpace : garbage)
    {
		fwrite(&freeSpace, sizeof(int), 1, file);
	}

	fclose(file);
}

long int findMovieAddress(int directorId, int movieId, int& error)
{
	long int address = getDirector(directorId, error).getFirstMovie();
	if (error)
    {
        return ABSENT_MARK;
    }
	while (address != END_MARK)
    {
		Movies movie = readMovie(moviesF, address);
		if (movie.getId() == movieId)
        {
            break;
        }
		address = movie.getNextMovie();
	}
	return address;
}

void prepare(char* directorsFilePath,
           char* freeSpacesAddressesFilePath,
           char* indexFilePath,
           char* moviesFilePath,
           int& error)
    {
    directorsF = fopen(directorsFilePath, "wb+");
	if (!directorsF)
    {
		error = CAN_NOT_LOAD_DIRECTORS_FILE_ERROR_CODE;
		return;
	}

	garbageAddresses = freeSpacesAddressesFilePath;
	loadFreeSpaceAddresses(error);
	if (error)
    {
        return;
    }

	indexAddresses = indexFilePath;
	loadIndexes(error);
	if (error)
    {
        return;
    }

    moviesF = fopen(moviesFilePath, "wb+");
	if (!moviesF)
    {
		error = CAN_NOT_LOAD_MOVIES_FILE_ERROR_CODE;
		return;
	}
}

void close(int& error)
{
	fclose(directorsF);

	writeFreeSpaceAddresses(error);
	if (error)
    {
        return;
    }

	writeIndexes(error);
	if (error)
    {
        return;
    }

	fclose(moviesF);
}

bool existsDirector(int id)
{
	return findDirectorAddress(id) != ABSENT_MARK;
}

void insertDirector(Directors director, int& error)
{
	if (garbage.empty())
    {
		fseek(directorsF, 0, SEEK_END);
	}
	else
    {
		fseek(directorsF, garbage.back(), SEEK_SET);
		garbage.pop_back();
	}
	indexes.emplace_back( director.getId(), ftell(directorsF) );
	sort(begin(indexes), end(indexes));
	writeDirector(director, directorsF);
}

void insertMovie(Movies movie, int& error)
{
	Directors director = getDirector(movie.getDirectorId(), error);
	if (error)
    {
        return;
    }

	long int newMovieAddress = getLastAddressInFile(moviesF);
	movie.setNextMovie(director.getFirstMovie());
	writeMovie(movie, newMovieAddress, moviesF);

	Movies nextMovie = readMovie(moviesF, director.getFirstMovie());
	nextMovie.setPreviousMovie(newMovieAddress);
	writeMovie(nextMovie, director.getFirstMovie(), moviesF);

	director.setFirstMovie(newMovieAddress);
	updateDirector(director, director.getId(), error);
}

void removeDirector(int id, int& error)
{
	int index = findDirectorInIndex(id);
	if (index == ABSENT_MARK)
    {
		error = CAN_NOT_FIND_DIRECTOR_ERROR_CODE;
		return;
	}

	long int address = indexes[index].second;
	Directors director = readDirector(directorsF, address);
	director.setState(MOVIE_REMOVED_STATE);
	writeDirector(director, address, directorsF);

	garbage.push_back(address);
	indexes.erase(begin(indexes) + index);
}

void removeMovie(int directorId, int movieId, int& error)
{
	long int movieAddress = findMovieAddress(directorId, movieId, error);
	if (error)
    {
        return;
    }
	if (movieAddress == ABSENT_MARK)
    {
		error = CAN_NOT_FIND_MOVIE_ERROR_CODE;
		return;
	}

	Movies movie = readMovie(moviesF, movieAddress);

	if (movie.getPreviousMovie() == ABSENT_MARK)
    {
		Directors director = getDirector(directorId, error);
		director.setFirstMovie(movie.getNextMovie());
		updateDirector(director, director.getId(), error);
	}
	else
    {
		Movies previousMovie = readMovie(moviesF, movie.getPreviousMovie());
		previousMovie.setNextMovie(movie.getNextMovie());
		updateMovie(previousMovie, directorId, previousMovie.getId(), error);
	}

	movie.setState(MOVIE_REMOVED_STATE);
	writeMovie(movie, movieAddress, moviesF);
}

void updateDirector(Directors director, int id, int& error)
{
	long int address = findDirectorAddress(id);
	if (address == ABSENT_MARK)
    {
		error = CAN_NOT_FIND_DIRECTOR_ERROR_CODE;
		return;
	}
	writeDirector(director, address, directorsF);
}

void updateMovie(Movies movie, int directorId, int id, int& error)
{
	long address = findMovieAddress(directorId, id, error);
	if (error)
    {
        return;
    }
	if (address == ABSENT_MARK)
    {
		error = CAN_NOT_FIND_MOVIE_ERROR_CODE;
		return;
	}
	writeMovie(movie, address, moviesF);
}

Directors getDirector(int id, int& error)
{
	long address = findDirectorAddress(id);
	if (address == ABSENT_MARK)
    {
		error = CAN_NOT_FIND_DIRECTOR_ERROR_CODE;
		return {};
	}
	return readDirector(directorsF, address);
}

Movies getMovie(int directorId, int id, int& error)
{
	long int address = findMovieAddress(directorId, id, error);
	if (error)
    {
        return {};
    }
	if (address == ABSENT_MARK)
    {
		error = CAN_NOT_FIND_MOVIE_ERROR_CODE;
		return {};
	}
	return readMovie(moviesF, address);
}

long countAllDirectors()
{
	return (long)indexes.size();
}

long countMoviesForDirector(int directorId, int& error)
{
	long address = getDirector(directorId, error).getFirstMovie(), result = 0;
	if (error)
    {
        return 0;
    }
	while (address != END_MARK) {
		Movies movie = readMovie(moviesF, address);
		address = movie.getNextMovie();
		result += movie.getState() == MOVIE_ACTIVE_STATE;
	}
	return result;
}

long countAllMovies()
{
    int error = 0;
    long result = 0;
    for (auto & g : indexes)
    {
        result += countMoviesForDirector(g.first, error);
    }
    return result;
}
