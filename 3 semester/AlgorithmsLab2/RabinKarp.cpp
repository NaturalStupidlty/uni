#include "RabinKarp.h"

long long RabinKarp::powerUnderMod(uint number)
{
    if (number == 0)
    {
        return 1;
    }
    if (number == 1)
    {
        return radix % mod;
    }
    long long pow = powerUnderMod(number / 2);
    if (number & 1)
    {
        return ((radix % mod) * (pow) % mod * (pow) % mod) % mod;
    }
    else
    {
        return ((pow) % mod * (pow) % mod) % mod;
    }
}

bool RabinKarp::check(vector<string> &text, vector<string> &pattern, long long int row, uint column) const
{
    if (patternRows + row >= textRows or patternColumns + row >= textColumns)
    {
        return false;
    }
    for (uint i = 0; i < patternRows; i++)
    {
        for (uint j = 0; j < patternColumns; j++)
        {
            if (pattern[i][j] != text[i + row][j + column])
            {
                return false;
            }
        }
    }
    return true;
}

vector<long long> RabinKarp::findHash(vector<string> &matrix) const
{
    vector<long long> hash;
    uint col = matrix[0].size();
    for (uint i = 0; i < col; i++)
    {
        long long rowHash = 0;
        for(uint j = 0; j < patternRows; j++)
        {
            rowHash = ((rowHash * radix) % mod + matrix[j][i] % mod) % mod;
        }
        hash.push_back(rowHash);
    }
    return hash;
}

void RabinKarp::rollingHash(vector<long long int> &textHash, long long int &textMatrixHash, uint row)
{
    textMatrixHash = (textMatrixHash % mod - ((textHash[row] % mod) * (maxColumnPower % mod)) % mod + mod) % mod;
    textMatrixHash = (textMatrixHash % mod * radix % mod) % mod;
    textMatrixHash = (textMatrixHash % mod + textHash[row + patternColumns] % mod) % mod;
}

void RabinKarp::columnRollingHash(vector<string> &text, vector<long long int> &textHash, uint row) const
{
    for (uint i = 0; i < textHash.size(); i++)
    {
        textHash[i] = (textHash[i] % mod - ((text[row][i]) % mod * (maxRowPower) % mod) % mod) % mod;
        textHash[i] = ((textHash[i] % mod) * (radix % mod)) % mod;
        textHash[i] = (textHash[i] % mod + text[row + patternRows][i] % mod) % mod;
    }
}

vector<pair<uint, uint>> RabinKarp::rabinKarpSearch(vector<string> &text, vector<string> &pattern)
{
    vector<pair<uint, uint>> indexes;

    textRows = text.size();
    textColumns = text[0].size();
    patternRows = pattern.size();
    patternColumns = pattern[0].size();

    maxRowPower = powerUnderMod(patternRows - 1);
    maxColumnPower = powerUnderMod(patternColumns - 1);

    vector<long long> textHash = findHash(text);
    vector<long long> patternHash = findHash(pattern);

    long long patternMatrixHash = 0;
    for (uint i = 0; i < patternColumns; i++)
    {
        patternMatrixHash = (patternMatrixHash * radix + patternHash[i]) % mod;
    }
    for (uint i = 0; i <= (textRows - patternRows); i++)
    {
        long long textMatrixHash = 0;
        for (uint j = 0; j < patternColumns; j++)
        {
            textMatrixHash = ((textMatrixHash * radix) + textHash[j]) % mod;
        }
        for (uint j = 0; j <= (textColumns - patternColumns); j++)
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
            rollingHash(textHash, textMatrixHash, j);
        }
        if (i < (textRows - patternRows))
        {
            columnRollingHash(text, textHash, i);
        }
    }
    return indexes;
}

vector<pair<uint, uint>> RabinKarp::naiveSearch(vector<string> &text, vector<string> &pattern) const
{
    vector<pair<uint, uint>> indexes;

    for (int i = 0; i < textRows - patternRows; i++)
    {
        for (int j = 0; j < textColumns - patternColumns; j++)
        {
            if (check(text, pattern, i, j))
            {
                pair<uint, uint> upperLeftIndex;
                upperLeftIndex.first = i;
                upperLeftIndex.second = j;
                indexes.emplace_back(upperLeftIndex);
            }
        }
    }
    return indexes;
}
