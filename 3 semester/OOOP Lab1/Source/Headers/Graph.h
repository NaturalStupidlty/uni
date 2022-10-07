#ifndef OOOP_LAB1_GRAPH_H
#define OOOP_LAB1_GRAPH_H

#include "Errors.h"

/** ------[ Базовий клас графа ]------ **/
template <typename vertexT, typename edgeT>
class Graph
{
protected:
    // Кількість вершин
    uint numberOfVertices{};

    // Конструктор
    explicit Graph(uint numberOfVertices = 1)
    {;
        if (numberOfVertices > 0)
        {
            this->numberOfVertices = numberOfVertices;
        }
        else
        {
            int error = 1;
            printError(error);
        }
    }

    // Віртуальний деструктор для коректної
    // роботи з вказівниками/посиланнями на базовий клас
    virtual ~Graph() = default;

public:
    // Додавання ребра
    virtual void addEdge(uint startVertex, uint endVertex, vertexT vertexData, edgeT edgeData) = 0;

    // Перевірка зв'язності
    virtual bool isConnected() = 0;

    // Відстань між двома заданими вершинами
    virtual int findDistance(uint startVertex, uint endVertex) = 0;

    virtual Graph<vertexT, edgeT>* getTransposed() = 0;

    // BFS обхід
    virtual void BFS(uint vertex) = 0;

    // DFS обхід
    virtual void DFS(uint vertex) = 0;
};

#endif //OOOP_LAB1_GRAPH_H
