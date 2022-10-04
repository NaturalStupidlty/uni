#ifndef OOOP_LAB1_MATRIXGRAPH_H
#define OOOP_LAB1_MATRIXGRAPH_H

#include <vector>
#include "Graph.h"
#include "Data.h"

using std::vector;

// Клас для графу, представленого матрицею суміжності
template <typename vertexT, typename edgeT> class MatrixGraph: public Graph<vertexT, edgeT>
{
private:
    // Матриця суміжності
    vector<vector<Data<vertexT, edgeT>>> matrix;

    // DFS обхід (допоміжна функція)
    void DFSUtil(Data<vertexT, edgeT> v, std::vector<bool> &visited, bool print = false)
    {
        // Відвідуємо поточну вершину
        visited[v.number] = true;
        if (print)
        {
            cout << v.number;
        }

        // Рекурсивно проходимо інші вершини
        for (auto i = 0; i < matrix[v.number].size(); ++i)
        {
            if (matrix[v.number][i].number >= 0 and !visited[matrix[v.number][i].number])
            {
                DFSUtil(matrix[v.number][i], visited, print);
            }
        }
    }

public:
    // Конструктор
    explicit MatrixGraph(int numberOfVertices) : Graph<vertexT, edgeT>(numberOfVertices)
    {
        for (int i = 0; i < numberOfVertices; ++i)
        {
            vector<Data<vertexT, edgeT>> line;
            for (int j = 0; j < numberOfVertices; ++j)
            {
                Data<vertexT, edgeT> data;
                line.push_back(data);
            }
            matrix.push_back(line);
        }
    }

    // Віртуальний деструктор для коректної
    // роботи з вказівниками на базовий клас
    virtual ~MatrixGraph() = default;

    // Додавання ребра
    void addEdge(int v, int w, vertexT vertexData, edgeT edgeData) override
    {
        if (v >= 0 and w >= 0)
        {
            Data<vertexT, edgeT> edge(vertexData, edgeData, w);
            this->matrix[v][w] = edge;
        }
        else
        {
            int error = 1;
            printError(error);
        }
    }

    // Знайти транспонований граф
    MatrixGraph<vertexT, edgeT> getTransposed()
    {
        MatrixGraph<vertexT, edgeT> transposedGraph(this->numberOfVertices);
        for (int i = 0; i < matrix.size(); ++i)
        {
            for(int j = 0; j < matrix.size(); ++j)
            {
                transposedGraph.matrix[i][j] = matrix[j][i];
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
            for (j = 0; this->numberOfVertices; ++j)
            {
                if (matrix[i][j].number >= 0)
                {
                    DFSUtil(matrix[i][j], visited);
                    break;
                }
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
        MatrixGraph<vertexT, edgeT> transposedGraph = getTransposed();

        visited.resize(this->numberOfVertices,false);

        // DFS другий раз
        DFSUtil(matrix[i][j], visited);

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
    int findDistance(int v, int w) override
    {
        vector<bool> visited;
        vector<int> distance;
        visited.resize(this->numberOfVertices,false);
        distance.resize(this->numberOfVertices,0);

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
            for (auto i = 0; i < matrix[v].size(); ++i)
            {
                if (matrix[v][i].number >= 0 and !visited[matrix[v][i].number])
                {
                    queue.push(matrix[v][i].number);
                    visited[matrix[v][i].number] = true;
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
        for (int i = 0; i < matrix.size(); ++i)
        {
            if (matrix[i][v].number == v)
            {
                w = matrix[i][v];
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
            for (auto i = 0; i < matrix[w.number].size(); ++i)
            {
                if (matrix[w.number][i].number >= 0 and !visited[matrix[w.number][i].number])
                {
                    queue.push(matrix[w.number][i]);
                    visited[matrix[w.number][i].number] = true;
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
        for (int i = 0; i < matrix.size(); ++i)
        {
            if (matrix[i][v].number == v)
            {
                w = matrix[i][v];
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
