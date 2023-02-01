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
    uint radix = 26;
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
    // O(M1 * M2), M1 = patternRows, M2 = patternColumns
    bool check(vector<string> &text, vector<string> &pattern, long long row, uint column) const;

    // Знаходить хеш перших patternSize рядків
    // O(N2*), N2 = matrix columns, M1 = patternRows
    vector<long long> findHash(vector<string> &matrix) const;

    // Rolling hash для рядочків
    // O(1)
    void rollingHash(vector<long long> &textHash, long long &textMatrixHash, uint row);

    // Rolling hash для стовпчиків
    // O(N), N = textHash.size()
    void columnRollingHash(vector<string> &text, vector<long long> &textHash, uint row) const;

public:
    RabinKarp() = default;
    // Алгоритм Рабіна-Карпа
    // Повертає індекси лівих верхніх кутів входжень
    // O((N1-M1) * (N2 - M2) * (M1 * M2)), N1 = textRows, N2 = textColumns, M1 = patternRows, M2 = patternColumns
    vector<pair<uint, uint>> rabinKarpSearch(vector<string> &text, vector<string> &pattern);
    vector<pair<uint, uint>> naiveSearch(vector<string> &text, vector<string> &pattern) const;
};
#endif //ALGORITHMSLAB2_RABINKARP_H
