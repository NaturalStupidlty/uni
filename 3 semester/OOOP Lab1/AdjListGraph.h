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
template <typename vertexT, typename edgeT> class AdjListGraph: public Graph<vertexT, edgeT>
{
private:
    // Список суміжних вершин
    vector<list<Data<vertexT, edgeT>>> adj;

    // DFS обхід (допоміжна функція)
    void DFSUtil(Data<vertexT, edgeT> v, vector<bool> &visited, bool print = false)
    {
        // Відвідуємо поточну вершину
        visited[v.number] = true;
        if (print)
        {
            cout << v.number;
        }

        // Рекурсивно проходимо інші вершини
        for (Data<vertexT, edgeT> adjacent: adj[v.number])
        {
            if (!visited[adjacent.number])
            {
                DFSUtil(adjacent, visited, print);
            }
        }
    }

public:
    // Конструктор
    explicit AdjListGraph(int numberOfVertices) : Graph<vertexT, edgeT>(numberOfVertices)
    {
        adj.resize(numberOfVertices);
    }

    // Віртуальний деструктор для коректної
    // роботи з вказівниками на базовий клас
    virtual ~AdjListGraph() = default;

    // Додавання ребра
    void addEdge(int v, int w, vertexT vertexData, edgeT edgeData) override {
        if (v >= 0 and w >= 0)
        {
            Data<vertexT, edgeT> edge(vertexData, edgeData, w);
            adj[v].push_back(edge);
        }
        else
        {
            int error = 1;
            printError(error);
        }
    }

    // Знайти транспонований граф
    AdjListGraph<vertexT, edgeT> getTransposed()
    {
        AdjListGraph<vertexT, edgeT> newGraph(this->numberOfVertices);
        for (int v = 0; v < adj.size(); ++v)
        {
            for (auto it = newGraph.adj[v].begin(); it != newGraph.adj[v].end(); ++it)
            {
                Data<vertexT, edgeT> data((*it).vertexData, (*it).edgeData, v);
                newGraph.adj[(*it).number].push_back(data);
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
        DFSUtil(*(adj[0].begin()), visited);

        // Перевіряємо чи відвідали всі вершини
        for (int i = 0; i < this->numberOfVertices; ++i)
        {
            if (!visited[i])
            {
                return false;
            }
        }

        // Транспонуємо граф
        AdjListGraph<vertexT, edgeT> transposedGraph = getTransposed();

        visited.resize(this->numberOfVertices,false);

        // DFS другий раз
        DFSUtil(*(adj[0].begin()), visited);

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
    int findDistance(int v, int w) override
    {
        vector<bool> visited(this->numberOfVertices,false);
        vector<int> distance(this->numberOfVertices, 0);

        // Черга для BFS
        queue<int> queue;

        // Відвідуємо поточний вузол та додаємо до черги
        visited[v] = true;
        queue.push(v);

        while(!queue.empty())
        {
            // Видалення вузла з черги
            v = queue.front();
            queue.pop();
            distance[v] = distance[v] + 1;

            // Отримуємо всі суміжні вершини вилученої з черги вершини s.
            // Якщо сусідня вершина не відвідана,
            // відвідуємо її й додаємо до черги.
            for (Data<vertexT, edgeT> adjacent: adj[v])
            {
                if (!visited[adjacent.number])
                {
                    visited[adjacent.number] = true;
                    queue.push(adjacent.number);
                }
            }
        }
        return distance[w];
    }

    // BFS обхід
    void BFS(int v) override
    {
        // Спочатку шукаємо початкову вершину,
        // щоб отримати доступ до її даних
        Data<vertexT, edgeT> w;
        for (int i = 0; i < adj.size(); ++i)
        {
            for (Data<vertexT, edgeT> adjacent: adj[i])
            {
                if (adjacent.number == v)
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
            for (Data<vertexT, edgeT> adjacent: adj[w.number])
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
    void DFS(int v) override
    {
        // Спочатку шукаємо початкову вершину,
        // щоб отримати доступ до її даних
        Data<vertexT, edgeT> w;
        for (int i = 0; i < adj.size(); ++i)
        {
            for (Data<vertexT, edgeT> adjacent: adj[i])
            {
                if (adjacent.number == v)
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
