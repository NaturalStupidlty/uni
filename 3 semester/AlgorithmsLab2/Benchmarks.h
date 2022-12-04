#ifndef ALGORITHMSLAB2_BENCHMARKS_H
#define ALGORITHMSLAB2_BENCHMARKS_H

#include "RabinKarp.h"
#include <chrono>
#include <iostream>

using namespace std::chrono;
using std::cout;
using std::endl;

void testRabinKarpSearch()
{
    cout << endl;
    vector<vector<char>> text;

    srand(0);

    int size = 10;
    for (int i = 0; i < size; i++)
    {
        vector <char> temp;
        for (int j = 0; j < size; j++)
        {
            temp.emplace_back((char)(rand() % 26 + 65));
        }
        text.emplace_back(temp);
    }
    int n = 5;
    int index = rand() % (size - n);
    int jndex = rand() % (size - n);


    for (int i = 0; i < size; i++)
    {
        for (int k = 0; k < size; k++)
        {
            cout << text[i][k] << " ";
        }
        cout << endl;
    }

    vector<vector<char>> pattern;
    for (int k = index; k < index + n; k++)
    {
        vector<char>::const_iterator first = text[k].begin() + jndex;
        vector<char>::const_iterator last = text[k].begin() + jndex + n;
        vector<char> temp(first, last);
        pattern.emplace_back(temp);
    }


    cout << index << " " << jndex << endl;

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            cout << pattern[i][k] << " ";
        }
        cout << endl;
    }

    vector<pair<uint, uint>> occurrences;
    RabinKarp patternSearch;
    auto start = high_resolution_clock::now();

    occurrences = patternSearch.rabinKarpSearch(text, pattern);

    cout << "Паттерн входить до тексту " << occurrences.size() << " разів." << endl;
    for (int i = 0; i < occurrences.size(); i++)
    {
        cout << "Входження номер " << i << endl;
        cout << "(" << occurrences[i].first << "; " << occurrences[i].second << ")" << endl;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    long long int res = duration.count();
    cout << "Середній час виконання алгоритму Рабіна-Карпа: ";
    cout << res / 1000000 << " секунд, "
         << (res % 1000000) / 1000 << " мілісекунд i "
         << res % 1000 << " мікросекунд" << endl;
    cout << endl;
}

#endif //ALGORITHMSLAB2_BENCHMARKS_H
