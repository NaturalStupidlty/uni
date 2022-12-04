#ifndef ALGORITHMSLAB2_RABINKARP_H
#define ALGORITHMSLAB2_RABINKARP_H

#include <vector>
#include <iostream>

using std::vector;
using std::pair;


class RabinKarp
{
private:
    // Дільник
    const long long mod = 257;
    // Кількість символів у алфавіті
    const long long radix = 256;
    // Найбільший степінь для хешування
    long long highestPower = 1;
    // n
    uint textSize = 0;
    // m
    uint patternSize = 0;

    // повертає radix в степені n під mod
    // О(log N), N = number
    long long powerUnderMod(int number);

    // Перевіряє, чи всі значення pattern
    // збігаються з відповідною частиною text
    // O(N^2), N = patternSize
    bool check(vector<vector<char>> &text,
               vector<vector<char>> &pattern,
               uint row,
               uint column) const;

    // Знаходить хеш перших patternSize рядків
    // O(N*M), matrix is N*N, M = patternSize
    vector<long long> findHash(vector<vector<char>> &matrix) const;

    // O(N), N = patternSize
    void rollingHash(vector<long long> &textHash, long long &textMatrixHash) const;

    // Rolling hash для стовпчиків
    // O(N), N = patternSize
    void columnRollingHash(vector<vector<char>> &text,
                           vector<long long> &textHash,
                           uint row) const;
public:
    // Знайти всі входження pattern до text
    // у вигляді індексів верхніх лівих кутів входжень
    // O((N-M)^2*M), N = textSize, M = patternSize
    vector<pair<uint, uint>> rabinKarpSearch(vector<vector<char>> &text,
                         vector<vector<char>> &pattern);
};
#endif //ALGORITHMSLAB2_RABINKARP_H
