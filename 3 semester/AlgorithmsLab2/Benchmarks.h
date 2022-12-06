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
    vector<string> text;
    int n = 1280, m = 5;
    for (int i = 0; i < n; i++)
    {
        string row;
        for (int j = 0; j < n; j++) {
            row += ((char) (rand() % 26 + 65));
        }
        text.emplace_back(row);
    }

    int index = rand() % (n - m);
    int jndex = rand() % (n - m);

    vector<string> pattern;
    for (int k = index; k < index + m; k++)
    {
        string row = text[k].substr(jndex, jndex + m);
        pattern.emplace_back(row);
    }

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            cout << text[i][k] << " ";
        }
        cout << endl;
    }
    cout << index << " " << jndex << endl;
    for (int i = 0; i < m; i++)
    {
        for (int k = 0; k < m; k++)
        {
            cout << pattern[i][k] << " ";
        }
        cout << endl;
    }

    vector<pair<uint, uint>> occurrences;
    RabinKarp solver;
    auto start = high_resolution_clock::now();
    occurrences = solver.rabinKarpSearch(text, pattern);
    auto stop = high_resolution_clock::now();

    cout << "Паттерн входить до тексту " << occurrences.size() << " разів." << endl;
    for (int i = 0; i < occurrences.size(); i++)
    {
        cout << "Входження номер " << i + 1<< endl;
        cout << "(" << occurrences[i].first << "; " << occurrences[i].second << ")" << endl;
    }

    auto duration = duration_cast<microseconds>(stop - start);
    long long int res = duration.count();
    cout << "Час виконання алгоритму Рабіна-Карпа: ";
    cout << res / 1000000 << " секунд, "
         << (res % 1000000) / 1000 << " мілісекунд i "
         << res % 1000 << " мікросекунд" << endl;
    cout << endl;

    vector<pair<uint, uint>> occurrences2;
    start = high_resolution_clock::now();
    occurrences = solver.naiveSearch(text, pattern);
    stop = high_resolution_clock::now();

    cout << "Паттерн входить до тексту " << occurrences.size() << " разів." << endl;
    for (int i = 0; i < occurrences.size(); i++)
    {
        cout << "Входження номер " << i + 1<< endl;
        cout << "(" << occurrences[i].first << "; " << occurrences[i].second << ")" << endl;
    }

    duration = duration_cast<microseconds>(stop - start);
    res = duration.count();
    cout << "Час виконання наївного алгоритму: ";
    cout << res / 1000000 << " секунд, "
         << (res % 1000000) / 1000 << " мілісекунд i "
         << res % 1000 << " мікросекунд" << endl;
    cout << endl;
}

#endif //ALGORITHMSLAB2_BENCHMARKS_H
