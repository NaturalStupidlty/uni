#include <iostream>
#include <cstdio>
#include <cctype>

using namespace std;

struct Book
{
    char author[30];
    char name[40];
    char publisher[20];
    int year;
    int pages;
};

void FindBook(char ptr[], size_t s, int year, char**& books, Book &example, FILE * fp);
void BookStructure(Book &example, char ptr[], size_t s, FILE * fp);

// остання функція для заданої стрічки присвоює інформацію з неї полям структури
// щоб не ускладнювати інші функції

int main() {
    FILE *fp;
    if ((fp=fopen("book_binary.dat", "rb")) == nullptr)
    {
        printf("Cannot open the file :(");
        getchar();
        return 0;
    }
    else
    {
        Book example;
        const int s = 100;
        char name[s];
        int year;
        cout << "Enter an author's name: ";
        cin >> name;
        cout << "Enter year: ";
        cin >> year;
        const int n = 10, m = 40;
        char **searchedBooks = new char*[n];
        for (int i = 0; i < 5; i++)
            searchedBooks[i] = new char[m];
        searchedBooks[0][0] = 0; // для перевірки ситуації без знаходження книжок
        FindBook(name, s, year, searchedBooks, example, fp);
        if (searchedBooks[0][0])
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << searchedBooks[i][j];
                }
            }
        }
        else
        {
            cout << "There is no any book by this author after such year";
        }
        delete[] searchedBooks;
        fclose(fp);
        return 0;
    }
}

void FindBook(char ptr[], size_t s, int year, char**& books, Book &example, FILE * fp)
{
    while (!feof(fp))
    {
        BookStructure(example, ptr, s, fp);
        unsigned int nameSize = strlen(ptr);
        int booksCounter = 0;
        bool flag = true;
        for (int j = 0; j < nameSize; j++)
        {
            if (example.author[j] != ptr[j])
            {
                flag = false;
            }
        }
        if(flag)
        {
            if (year < example.year )
            {
                flag = false;
            }
        }
        if(flag)
        {
            unsigned int bookNameSize = strlen(example.name);
            for (int j = 0; j < bookNameSize; j++)
            {
                books[booksCounter][j] = example.name[j];
            }
        }
    }
}

void BookStructure(Book &example, char ptr[], size_t s, FILE * fp)
{
    int size = sizeof(Book);
    char str[s];
    fread(&str, size, 1, fp);
    int i = 0;
    for (; str[i]!=','; i++)
    {
        example.author[i] = str[i];
    }
    i++;
    {for (; str[i]!=','; i++)
        example.name[i] = str[i];
    }
    i++;
    for (; str[i]!=','; i++)
    {
        example.publisher[i] = str[i];
    }
    i++;
    char yearBuff[s];
    for (; str[i]!=','; i++)
    {
        yearBuff[i] = str[i];
    }
    i++;
    example.year = stoi (yearBuff);
    char pagesBuff[s];
    for (; str[i]!=','; i++)
    {
        pagesBuff[i] = str[i];
    }
    example.pages = stoi (pagesBuff);
}


