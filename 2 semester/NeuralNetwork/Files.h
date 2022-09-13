#ifndef NEURALNETWORK_FILES_H
#define NEURALNETWORK_FILES_H

#include "NeuralNetwork.h"
#include <string>
#include <fstream>

void ReadCSV(const std::string& filename, std::vector<RowVector*>& data);
void genData(const std::string& filename, int lines);

#endif //NEURALNETWORK_FILES_H
