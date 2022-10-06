#ifndef OOOP_LAB1_MATRIXGRAPH_H
#define OOOP_LAB1_MATRIXGRAPH_H

#include <vector>
#include "Graph.h"
#include "Data.h"

using std::vector;

// Клас для графу, представленого матрицею суміжності
template <typename vertexT, typename edgeT>
class MatrixGraph: public Graph<vertexT, edgeT>
{
private:
    // Матриця суміжності
    vector<vector<Data<vertexT, edgeT>>> adjacencyMatrix;

    // DFS обхід (допоміжна функція)
    void DFSUtil(Data<vertexT, edgeT> vertex, std::vector<bool> &visited, bool print = false)
    {
        // Відвідуємо поточну вершину
        visited[vertex.number] = true;
        if (print)
        {
            cout << vertex.number;
        }

        // Рекурсивно проходимо інші вершини
        for (auto i = 0; i < adjacencyMatrix[vertex.number].size(); ++i)
        {
            if (adjacencyMatrix[vertex.number][i].number >= 0 and !visited[adjacencyMatrix[vertex.number][i].number])
            {
                DFSUtil(adjacencyMatrix[vertex.number][i], visited, print);
            }
        }
    }

public:
    // Конструктор
    explicit MatrixGraph(uint numberOfVertices) : Graph<vertexT, edgeT>(numberOfVertices)
    {
        for (int i = 0; i < numberOfVertices; ++i)
        {
            vector<Data<vertexT, edgeT>> line;
            for (int j = 0; j < numberOfVertices; ++j)
            {
                Data<vertexT, edgeT> data;
                line.push_back(data);
            }
            adjacencyMatrix.push_back(line);
        }
    }

    // Віртуальний деструктор для коректної
    // роботи з вказівниками на базовий клас
    virtual ~MatrixGraph() = default;

    // Додавання ребра
    void addEdge(uint startVertex, uint endVertex, vertexT vertexData, edgeT edgeData) override
    {
        if (startVertex < this->numberOfVertices and endVertex < this->numberOfVertices)
        {
            Data<vertexT, edgeT> edge(vertexData, edgeData, endVertex);
            this->adjacencyMatrix[startVertex][endVertex] = edge;
        }
        else
        {
            uint error = 2;
            printError(error);
        }
    }

    // Знайти транспонований граф
    MatrixGraph<vertexT, edgeT>* getTransposed() override
    {
        auto* transposedGraph = new MatrixGraph<vertexT, edgeT>(this->numberOfVertices);
        for (int i = 0; i < this->adjacencyMatrix.size(); ++i)
        {
            for(int j = 0; j < this->adjacencyMatrix.size(); ++j)
            {
                transposedGraph->adjacencyMatrix[i][j] = this->adjacencyMatrix[j][i];
            }
        }
        return transposedGraph;
    }

    // Перевірка зв'язності
    bool isConnected() override
    {
        // Ні одна вершина ще не відвідана
        vector<bool> visited(this->numberOfVertices, false);

        int i, j;
        // DFS перший раз
        for (i = 0; i < this->numberOfVertices; ++i)
        {
            bool flag = true;
            for (j = 0; j < this->numberOfVertices; ++j)
            {
                if (adjacencyMatrix[i][j].number >= 0)
                {
                    DFSUtil(adjacencyMatrix[i][j], visited);
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                break;
            }
        }

        // Перевіряємо чи відвідали всі вершини
        for (int k = 0; k < this->numberOfVertices; ++k)
        {
            if (!visited[k])
            {
                return false;
            }
        }

        // Транспонуємо граф
        MatrixGraph<vertexT, edgeT>* transposedGraph = getTransposed();

        visited.resize(this->numberOfVertices,false);

        // DFS другий раз
        DFSUtil(transposedGraph->adjacencyMatrix[i][j], visited);

        // Перевіряжмо чи відвідали всі вершини
        for (int k = 0; k < this->numberOfVertices; ++k)
        {
            if (!visited[k])
            {
                return false;
            }
        }
        return true;
    }

    // Знаходження відстані між двома вершинами
    int findDistance(uint startVertex, uint endVertex) override
    {
        vector<bool> visited;
        vector<int> distance;
        visited.resize(this->numberOfVertices,false);
        distance.resize(this->numberOfVertices,0);

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
            for (auto i = 0; i < adjacencyMatrix[startVertex].size(); ++i)
            {
                if (adjacencyMatrix[startVertex][i].number >= 0 and !visited[adjacencyMatrix[startVertex][i].number])
                {
                    queue.push(adjacencyMatrix[startVertex][i].number);
                    visited[adjacencyMatrix[startVertex][i].number] = true;
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
        for (int i = 0; i < adjacencyMatrix.size(); ++i)
        {
            if (adjacencyMatrix[i][vertex].number == vertex)
            {
                w = adjacencyMatrix[i][vertex];
            }
        }

        // Ні одна вершина ще не відвідана
        vector<bool> visited;
        visited.resize(this->numberOfVertices,false);

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

            // Отримуємо всі суміжні вершини вилученої з черги вершини w.
            // Якщо сусідня вершина не відвідана,
            // відвідуємо її й додаємо до черги.
            for (auto i = 0; i < adjacencyMatrix[w.number].size(); ++i)
            {
                if (adjacencyMatrix[w.number][i].number >= 0 and !visited[adjacencyMatrix[w.number][i].number])
                {
                    queue.push(adjacencyMatrix[w.number][i]);
                    visited[adjacencyMatrix[w.number][i].number] = true;
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
        for (int i = 0; i < adjacencyMatrix.size(); ++i)
        {
            if (adjacencyMatrix[i][vertex].number == vertex)
            {
                w = adjacencyMatrix[i][vertex];
            }
        }

        // Ні одна вершина ще не відвідана
        vector<bool> visited(this->numberOfVertices, false);
        DFSUtil(w, visited, true);
    }

/*
    // Перевірка на часткову зв'язність
    bool isUnilaterallyConnected()
    {
        for (int i = 0; i < matrix.size(); ++i)
        {

            for (int j = 0; j < matrix[i].size(); ++j)
            {
                if ((i > j && matrix[i][j].number == -1)
                    or (i < j && matrix[i][j].number == -1))
                {
                    return false;
                }
            }
        }
        return true;
    }
*/
};

#endif //OOOP_LAB1_MATRIXGRAPH_H
