// #include "RabinKarp.h"
#include "Benchmarks.h"
#include <iostream>
#include <vector>

using std::vector;
using std::pair;
using std::cout;
using std::endl;

int main()
{
    testRabinKarpSearch();


/*    vector<vector<char>> text { {'A', 'B', 'C', 'D', 'E'},
                              {'A', 'B', 'C', 'D', 'E'},
                              {'A', 'B', 'C', 'D', 'E'},
                              {'A', 'B', 'C', 'D', 'E'},
                              {'A', 'B', 'C', 'D', 'E'} };

    vector<vector<char>> pattern { {'A', 'B', 'C', 'D'},
                                 {'A', 'B', 'C', 'D'},
                                 {'A', 'B', 'C', 'D'},
                                 {'A', 'B', 'C', 'D'} };

    vector<pair<uint, uint>> occurrences;
    RabinKarp patternSearch;
    occurrences = patternSearch.rabinKarpSearch(text, pattern);

    cout << "Паттерн входить до тексту " << occurrences.size() << " разів." << endl;
    for (int i = 0; i < occurrences.size(); i++)
    {
        cout << "Входження номер " << i << endl;
        cout << "(" << occurrences[i].first << "; " << occurrences[i].second << ")" << endl;
    }*/
    return 0;
}