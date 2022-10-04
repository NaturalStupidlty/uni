#ifndef OOOP_LAB1_GRAPH_H
#define OOOP_LAB1_GRAPH_H

#include "Errors.h"

// Базовий клас графу
template <typename vertexT, typename edgeT> class Graph
{
protected:
    // Кількість вершин
    int numberOfVertices{};

    // Коструктор
    explicit Graph(int numberOfVertices = 1)
    {
        if (numberOfVertices > 0)
        {
            this->numberOfVertices = numberOfVertices;
        }
        else
        {
            printError(2);
        }
    }

    // Віртуальний деструктор для коректної
    // роботи з вказівниками на базовий клас
    virtual ~Graph() = default;

public:
    // Додавання ребра
    virtual void addEdge(int v, int w, vertexT vertexData, edgeT edgeData) = 0;

    // Перевірка зв'язності
    virtual bool isConnected() = 0;

    // Відстань між двома заданими вершинами
    virtual int findDistance(int v, int w) = 0;

    // BFS обхід
    virtual void BFS(int v) = 0;

    // DFS обхід
    virtual void DFS(int v) = 0;
};

#endif //OOOP_LAB1_GRAPH_H
