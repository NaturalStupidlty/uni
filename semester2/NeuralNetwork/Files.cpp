#include "Files.h"
#include <random>

using namespace std;

void ReadCSV(const string& filename, vector<RowVector*>& data)
{
    data.clear();
    ifstream file(filename);
    string line, word;
    getline(file, line, '\n'); // кількість стовпчиків у файлі
    stringstream ss(line);
    vector<Scalar> parsed_vector;
    while (getline(ss, word, ','))
    {
        // розбираємо вираз на складові за розділовим символом
        parsed_vector.push_back(Scalar(stof(&word[0])));
    }
    uint cols = parsed_vector.size();
    data.push_back(new RowVector(cols));
    for (int i = 0; i < cols; i++)
    {
        data.back()->coeffRef(1, i) = parsed_vector[i];
    }

    // читання файлу
    if (file.is_open())
    {
        while (getline(file, line, '\n'))
        {
            stringstream string_line(line);
            data.push_back(new RowVector(1, cols));
            int i = 0;
            while (getline(string_line, word, ','))
            {
                data.back()->coeffRef(i) = Scalar(stof(&word[0]));
                i++;
            }
        }
    }
}

// генерація відносно випадкових даних
void genData(const string& filename, int lines)
{
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(1, 1000);
    ofstream file1(filename + "-in");
    ofstream file2(filename + "-out");
    for (int r = 0; r < lines; r++)
    {
        Scalar x =  rand() / Scalar(RAND_MAX);
        Scalar y = rand() / Scalar(RAND_MAX);
        file1 << x << "," << y << endl;
        // будь-яка зміна даних, яку буде передбачувати нейронна мережа
        file2 << x * x + pow(y, 0.765) - tanh(x) << endl;
    }
    file1.close();
    file2.close();

}


