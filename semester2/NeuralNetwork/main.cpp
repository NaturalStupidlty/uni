#include "NeuralNetwork.h"
#include "Files.h"

using namespace std;

int main()
{
    const int n = 10000;
    const float learning_speed = 0.001;
    NeuralNetwork Genius({ 2, 3, 1 }, learning_speed);
    vector<RowVector*> input_data, output_data;
    genData("Data", n);
    ReadCSV("Data-in", input_data);
    ReadCSV("Data-out", output_data);
    Genius.train(input_data, output_data);
    return 0;
}