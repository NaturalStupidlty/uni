#ifndef OOOP_LAB1_ADJLISTGRAPH_H
#define OOOP_LAB1_ADJLISTGRAPH_H

#include <iostream>
#include <queue>
#include <list>
#include <vector>
#include "Data.h"
#include "Graph.h"
#include "Errors.h"

using std::vector;
using std::queue;
using std::list;
using std::cout;
using std::endl;

// Клас для графу, представленого списком суміжності
template <typename vertexT, typename edgeT>
class AdjListGraph: public Graph<vertexT, edgeT>
{
private:
    // Список суміжних вершин
    vector<list<Data<vertexT, edgeT>>> adjacencyList;

    // DFS обхід (допоміжна функція)
    void DFSUtil(Data<vertexT, edgeT> vertex, vector<bool> &visited, bool print = false)
    {
        // Відвідуємо поточну вершину
        visited[vertex.number] = true;
        if (print)
        {
            cout << vertex.number;
        }

        // Рекурсивно проходимо інші вершини
        for (Data<vertexT, edgeT> adjacent: adjacencyList[vertex.number])
        {
            if (!visited[adjacent.number])
            {
                    DFSUtil(adjacent, visited, print);
            }
        }
    }

public:
    // Конструктор
    explicit AdjListGraph(uint numberOfVertices) : Graph<vertexT, edgeT>(numberOfVertices)
    {
        adjacencyList.resize(numberOfVertices);
    }

    // Віртуальний деструктор для коректної
    // роботи з вказівниками/посиланнями на базовий клас
    virtual ~AdjListGraph() = default;

    // Додавання ребра
    void addEdge(uint startVertex, uint endVertex, vertexT vertexData, edgeT edgeData) override
    {
        if (startVertex < this->numberOfVertices and endVertex < this->numberOfVertices)
        {
            Data<vertexT, edgeT> edge(vertexData, edgeData, endVertex);
            adjacencyList[startVertex].push_back(edge);
        }
        else
        {
            uint error = 2;
            printError(error);
        }
    }

    // Знайти транспонований граф
    AdjListGraph<vertexT, edgeT>* getTransposed() override
    {
        auto* newGraph = new AdjListGraph<vertexT, edgeT>(this->numberOfVertices);
        for (int v = 0; v < adjacencyList.size(); ++v)
        {
            for (auto it = newGraph->adjacencyList[v].begin(); it != newGraph->adjacencyList[v].end(); ++it)
            {
                Data<vertexT, edgeT> data((*it).vertexData, (*it).edgeData, v);
                newGraph->adjacencyList[(*it).number].push_back(data);
            }
        }
        return newGraph;
    }

    // Перевірка зв'язності
    bool isConnected() override
    {
        // Ні одна вершина ще не відвідана
        vector<bool> visited(this->numberOfVertices, false);

        // DFS перший раз
        DFSUtil(*(this->adjacencyList[0].begin()), visited);

        // Перевіряємо чи відвідали всі вершини
        for (int i = 0; i < this->numberOfVertices; ++i)
        {
            if (!visited[i])
            {
                return false;
            }
        }

        // Транспонуємо граф
        AdjListGraph<vertexT, edgeT>* transposedGraph = getTransposed();

        visited.resize(this->numberOfVertices,false);

        // DFS другий раз
        DFSUtil(*(transposedGraph->adjacencyList[0].begin()), visited);

        // Перевіряжмо чи відвідали всі вершини
        for (int i = 0; i < this->numberOfVertices; ++i)
        {
            if (!visited[i])
            {
                return false;
            }
        }
        return true;
    }

    // Знаходження відстані між двома вершинами
    int findDistance(uint startVertex, uint endVertex) override
    {
        vector<bool> visited(this->numberOfVertices,false);
        vector<int> distance(this->numberOfVertices, 0);

        // Черга для BFS
        queue<uint> queue;

        // Відвідуємо поточний вузол та додаємо до черги
        visited[startVertex] = true;
        queue.push(startVertex);

        while(!queue.empty())
        {
            // Видалення вузла з черги
            startVertex = queue.front();
            queue.pop();
            distance[startVertex] = distance[startVertex] + 1;

            // Отримуємо всі суміжні вершини вилученої з черги вершини s.
            // Якщо сусідня вершина не відвідана,
            // відвідуємо її й додаємо до черги.
            for (Data<vertexT, edgeT> adjacent: adjacencyList[startVertex])
            {
                if (!visited[adjacent.number])
                {
                    visited[adjacent.number] = true;
                    queue.push(adjacent.number);
                }
            }
        }
        return distance[endVertex];
    }

    // BFS обхід
    void BFS(uint vertex) override
    {
        // Спочатку шукаємо початкову вершину,
        // щоб отримати доступ до її даних
        Data<vertexT, edgeT> w;
        for (int i = 0; i < adjacencyList.size(); ++i)
        {
            for (Data<vertexT, edgeT> adjacent: adjacencyList[i])
            {
                if (adjacent.number == vertex)
                {
                    w = adjacent;
                    break;
                }
            }
        }

        // Ні одна вершина ще не відвідана
        vector<bool> visited(this->numberOfVertices, false);

        // Черга для BFS
        queue<Data<vertexT, edgeT>> queue;

        // Відвідуємо поточний вузол та додаємо до черги
        visited[w.number] = true;
        queue.push(w);

        while(!queue.empty())
        {
            // Видалення вузла з черги
            w = queue.front();
            cout << w.number;
            queue.pop();

            // Отримуємо всі суміжні вершини вилученої з черги вершини s.
            // Якщо сусідня вершина не відвідана,
            // відвідуємо її й додаємо до черги.
            for (Data<vertexT, edgeT> adjacent: adjacencyList[w.number])
            {
                if (!visited[adjacent.number])
                {
                    visited[adjacent.number] = true;
                    queue.push(adjacent);
                }
            }
        }
        cout << endl;
    }

    // DFS обхід (функція виклику)
    void DFS(uint vertex) override
    {
        // Спочатку шукаємо початкову вершину,
        // щоб отримати доступ до її даних
        Data<vertexT, edgeT> w;
        for (int i = 0; i < adjacencyList.size(); ++i)
        {
            for (Data<vertexT, edgeT> adjacent: adjacencyList[i])
            {
                if (adjacent.number == vertex)
                {
                    w = adjacent;
                    break;
                }
            }
        }

        // Ні одна вершина ще не відвідана
        vector<bool> visited(this->numberOfVertices, false);
        DFSUtil(w, visited, true);
    }

/*
    // Перевірка на часткову зв'язність ????????????????
    virtual bool isUnilaterallyConnected()
    {
        // список вершин, від яких не відходять зв'язки
        vector<int> emptyList;
        for (int i = 0; i < adj.size(); ++i)
        {
            if (adj[i].empty())
            {
                emptyList.push_back(i);
            }
        }

        for (int l = 0; l < emptyList.size(); ++l)
        {
            for (int i = 0; i < adj.size(); ++i)
            {
                for (auto it = adj[i].begin(); it != adj[i].end(); ++it)
                {
                    if (it->number == emptyList[l])
                    {
                        emptyList.erase(emptyList.begin()+l);
                    }
                }
            }
            return false;
        }
        return true;
    }
*/
};

#endif //OOOP_LAB1_ADJLISTGRAPH_H
