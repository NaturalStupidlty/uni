#ifndef NEURALNETWORK_NEURALNETWORK_H
#define NEURALNETWORK_NEURALNETWORK_H

#include "../eigen/Eigen/Eigen" // бібліотека для роботи з лінійною алгеброю
#include <iostream>
#include <vector>

typedef float Scalar;
typedef Eigen::MatrixXf Matrix;
typedef Eigen::RowVectorXf RowVector;

class NeuralNetwork {
public:
    // конструктор
    explicit NeuralNetwork(std::vector<uint> topology, Scalar learningRate = Scalar(0.001));

    // поширення даних
    void propagateForward(RowVector& input);

    // зворотнє поширення помилок нейронів
    void propagateBackward(RowVector& output);

    // обчислення помилок, зроблених нейронами на кожному шарові
    void calcErrors(RowVector& output);

    // оновити вагу зв'язків
    void updateWeights();

    // тренування нейромережі за заданим масивом точок
    void train(std::vector<RowVector*> input, std::vector<RowVector*> output);

    // об'єкти для роботи з нейромережею
    std::vector<RowVector*> neuronLayers; // зберігає різні шари нейромережі
    std::vector<RowVector*> cacheLayers; // зберігає неактивні значення шарів
    std::vector<RowVector*> deltas; // зберігає різницю помилок для кожного з нейронів
    std::vector<Matrix*> weights; // вага зв'язків
    std::vector<uint> topology; // кількість нейронів у кожному з шарів нейромережі
    Scalar learningRate; // швидкість навчання
};

#endif //NEURALNETWORK_NEURALNETWORK_H
