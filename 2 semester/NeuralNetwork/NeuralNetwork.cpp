#include "NeuralNetwork.h"

using namespace std;

Scalar activationFunction(Scalar x)
{
    // нелінійна функція для активації
    return tanhf(x);
}

Scalar activationFunctionDerivative(Scalar x)
{
    // похідна
    return 1 + tanhf(x) * tanhf(x);
}

NeuralNetwork::NeuralNetwork(vector<uint> topology, Scalar learningRate)
{
    this->topology = topology;
    this->learningRate = learningRate;
    for (int i = 0; i < topology.size(); i++)
    {
        if (i == topology.size() - 1)
        {
            neuronLayers.push_back(new RowVector(topology[i]));
        }
        else
        {
            neuronLayers.push_back(new RowVector(topology[i] + 1));
        }
        cacheLayers.push_back(new RowVector (neuronLayers.size()));
        deltas.push_back((new RowVector(neuronLayers.size())));
        if (i != topology.size() - 1)
        {
            neuronLayers.back()->coeffRef(topology[i]) = 1.0;
            cacheLayers.back()->coeffRef(topology[i]) = 1.0;
        }
        if (i > 0)
        {
            if (i != topology.size() - 1)
            {
                weights.push_back(new Matrix(topology[i - 1] + 1, topology[i] + 1));
                weights.back()->setRandom();
                weights.back()->col(topology[i]).setZero();
                weights.back()->coeffRef(topology[i - 1], topology[i]) = 1.0;
            }
            else
            {
                weights.push_back(new Matrix(topology[i - 1] + 1, topology[i]));
                weights.back()->setRandom();
            }
        }
    }
}

void NeuralNetwork::propagateForward(RowVector& input)
{
    // щоб нейрони зміщення залишилися без змін робимо
    // всі елементи останнього стовпчика 0, окрім останнього
    neuronLayers.front()->block(0, 0, 1, neuronLayers.front()->size() - 1);
    for (int i = 1; i < topology.size(); i++)
    {
        // поширюємо дані застосовуючи функцію активації для кожного елемента
        (*neuronLayers[i]) = (*neuronLayers[i - 1]) * (*weights[i - 1]);
        neuronLayers[i]->block
                (0, 0, 1, topology[i]).unaryExpr(cref(activationFunction));
    }
}

void NeuralNetwork::propagateBackward(RowVector &output)
{
    calcErrors(output);
    updateWeights();
}

void NeuralNetwork::calcErrors(RowVector& output)
{
    // помилки зроблені нейронами останнього шару
    (*deltas.back()) = output - (*neuronLayers.back());

    // помилки зроблені нейронами прихованих шарів
    // рахуємо від останнього до першого
    for (uint i = topology.size() - 2; i > 0; i--)
    {
        (*deltas[i]) = (*deltas[i - 1]) * (weights[i]->transpose());
    }
}

void NeuralNetwork::updateWeights()
{
    // topology.size()-1 = weights.size()
    for (int i = 0; i < topology.size() - 1; i++)
    {
        // для кожного шару нейромережі
        // якщо це output, то нейрона зміщення немає і вказана к-сть нейронів = к-сть стовпчиків
        // якщо ні, то вказана к-сть нейронів = к-сть стовпчиків - 1

        /*
        c-й стовпець у матриці ваги представляє з'єднання c-го нейрона в CURRENT_LAYER до всіх нейронів PREV_LAYER.
        r-й елемент c-го стовпця в матриці ваги представляє з'єднання c-го нейрона в CURRENT_LAYER до r-го нейрона в PREV_LAYER.
        r-й рядок у матриці ваги представляє з'єднання всіх нейронів PREV_LAYER з r-им нейроном у CURRENT_LAYER.
        c-ий елемент r-го рядка в матриці ваги представляє з'єднання c-го нейрона в PREV_LAYER до r-го нейрона в CURRENT_LAYER.
         */
        if ( i != topology.size() - 2)
        {
            for (int c = 0; c < weights[i]->cols() - 1; c++)
            {
                for (int r = 0; r < weights[i]->rows(); r++)
                {
                    // за формулою
                    weights[i]->coeffRef(r, c) += learningRate * deltas[i + 1]->coeffRef(c)
                                                  * activationFunctionDerivative(cacheLayers[i + 1]->coeffRef(c))
                                                  * neuronLayers[i]->coeffRef(r);
                }
            }
        }
        else
        {
            for (int c = 0; c < weights[i]->cols(); c++)
            {
                for (int r = 0; r < weights[i]->rows(); r++)
                {
                    weights[i]->coeffRef(r, c) += learningRate * deltas[i + 1]->coeffRef(c)
                                                  * activationFunctionDerivative(cacheLayers[i + 1]->coeffRef(c))
                                                  * neuronLayers[i]->coeffRef(r);
                }
            }
        }
    }
}

void NeuralNetwork::train(vector<RowVector*> input_data, vector<RowVector*> output_data)
{
    for (int i = 0; i < input_data.size(); i++)
    {
        cout << "Вхідні дані нейронної мережі : " << *input_data[i] << endl;
        propagateForward(*input_data[i]);
        cout << "Очікуємий результат : " << *output_data[i] << endl;
        cout << "Отриманий результат : " << *neuronLayers.back() << endl;
        propagateBackward(*output_data[i]);
        // 𝑀𝑆𝐸 = 1/𝑛 * ∑𝑛𝑖(𝑦𝑖−𝑦𝑖')^2
        cout << "MSE (середня квадратична помилка): " << endl;
        cout << sqrt((*deltas.back()).dot((*deltas.back())) / (float)deltas.back()->size());
        cout << endl;
    }
}
