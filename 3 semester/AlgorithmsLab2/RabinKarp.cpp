#include "RabinKarp.h"

long long RabinKarp::powerUnderMod(int number)
{
    if (number == 0)
    {
        return 1;
    }
    if (number == 1)
    {
        return radix % mod;
    }
    long long power = powerUnderMod(number / 2);
    if (number & 1)
    {
        return ((radix % mod) * (power) % mod * (power) % mod) % mod;
    }
    else
    {
        return ((power) % mod * (power) % mod) % mod;
    }
}

bool RabinKarp::check(vector<vector<char>> &text,
                      vector<vector<char>> &pattern,
                      uint row,
                      uint column) const
{
    for (uint i = 0; i < patternSize; i++)
    {
        for (uint j = 0; j < patternSize; j++)
        {
            if (pattern[i][j] != text[i + row][j + column])
            {
                return false;
            }
        }
    }
    return true;
}

vector<long long> RabinKarp::findHash(vector<vector<char>> &matrix) const
{
    vector<long long> matrixHash;
    uint columns = matrix[0].size();
    for (uint i = 0; i < columns; i++)
    {
        long long rowHash = 0;
        for (uint j = 0; j < patternSize; j++)
        {
            rowHash = ((rowHash * radix) % mod + matrix[j][i] % mod) % mod;
        }
        matrixHash.emplace_back(rowHash);
    }
    return matrixHash;
}

void RabinKarp::rollingHash(vector<long long> &textHash, long long &textMatrixHash) const
{
    for (uint i = 0; i <= (textSize - patternSize); i++)
    {
        textMatrixHash = (textMatrixHash % mod - ((textHash[i] % mod) * (highestPower % mod)) % mod + mod) % mod;
        textMatrixHash = (textMatrixHash % mod * radix % mod) % mod;
        textMatrixHash = (textMatrixHash % mod + textHash[i + (textSize - patternSize)] % mod) % mod;
    }
}

void RabinKarp::columnRollingHash(vector<vector<char>> &text,
                                  vector<long long> &textHash,
                                  uint row) const
{
    for (uint i = 0; i < textHash.size(); i++)
    {
        textHash[i] = (textHash[i] % mod - ((text[row][i]) % mod * (highestPower) % mod) % mod) % mod;
        textHash[i] = ((textHash[i] % mod) * (radix % mod)) % mod;
        textHash[i] = (textHash[i] % mod + text[row + patternSize][i] % mod) % mod;
    }
}

vector<pair<uint, uint>> RabinKarp::rabinKarpSearch(vector<vector<char>> &text,
                                vector<vector<char>> &pattern)
{
    vector<pair<uint, uint>> indexes;
    textSize = text.size();
    patternSize = pattern.size();

    highestPower = powerUnderMod((int)patternSize - 1);

    // Хеш перших patternSize рядків
    vector<long long> textHash = findHash(text);
    vector<long long> patternHash = findHash(pattern);

    long long patternMatrixHash = 0;
    for (uint i = 0; i < patternSize; i++)
    {
        patternMatrixHash = (patternMatrixHash * radix + patternHash[i]) % mod;
    }

    for (uint i = 0; i <= (textSize - patternSize); i++)
    {
        long long textMatrixHash = 0;
        for (uint j = 0; j < patternSize; j++)
        {
            textMatrixHash = ((textMatrixHash * radix) + textHash[j]) % mod;
        }
        for (uint j = 0; j <= (textSize - patternSize); j++)
        {
            if (patternMatrixHash == textMatrixHash)
            {
                if (check(text, pattern, i, j))
                {
                    pair<uint, uint> upperLeftIndex;
                    upperLeftIndex.first = i;
                    upperLeftIndex.second = j;
                    indexes.emplace_back(upperLeftIndex);
                }
            }
            // Рахуємо textMatrixHash для наступних стовпчиків
            rollingHash(textHash, textMatrixHash);
        }
        if (i < textSize - patternSize)
        {
            // Хешування для наступного рядка
            columnRollingHash(text, textHash, i);
        }
    }
    return indexes;
}
