#ifndef ALGORITHMSLAB2_RABINKARP_H
#define ALGORITHMSLAB2_RABINKARP_H

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::pair;

class RabinKarp
{
private:
    // Дільник
    long long mod = 1e9 + 7;
    // Кількість символів у алфавіті
    uint radix = 24;
    // Найбільший степінь для хешування
    uint maxRowPower = 1;
    uint maxColumnPower = 1;

    // Розміри матриці
    uint textRows{};
    uint textColumns{};
    uint patternRows{};
    uint patternColumns{};

private:
    // повертає radix в степені n під mod
    // О(log N), N = number
    long long powerUnderMod(uint number);

    // Перевіряє, чи всі значення pattern
    // збігаються з відповідною частиною text
    // O(N^2), N = patternSize
    bool check(vector<string> &text, vector<string> &pattern, long long row, uint column) const;

    // Знаходить хеш перших patternSize рядків
    // O(N*M), matrix is N*N, M = patternSize
    vector<long long> findHash(vector<string> &matrix) const;

    // Rolling hash для рядочків
    // O(1)
    void rollingHash(vector<long long> &textHash, long long &textMatrixHash, uint row);

    // Rolling hash для стовпчиків
    // O(N), N = patternSize
    void columnRollingHash(vector<string> &text, vector<long long> &textHash, uint row) const;

public:
    RabinKarp() = default;
    vector<pair<uint, uint>> rabinKarpSearch(vector<string> &text, vector<string> &pattern);
    vector<pair<uint, uint>> naiveSearch(vector<string> &text, vector<string> &pattern) const;
};
#endif //ALGORITHMSLAB2_RABINKARP_H
