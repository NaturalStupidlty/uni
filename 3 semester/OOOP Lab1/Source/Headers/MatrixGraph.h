#ifndef OOOP_LAB1_MATRIXGRAPH_H
#define OOOP_LAB1_MATRIXGRAPH_H

#include <vector>
#include "Graph.h"
#include "Data.h"

using std::vector;

/** ------[ Клас для графа, представленого матрицею суміжності ]------ */

template <typename vertexT, typename edgeT>
class MatrixGraph: public Graph<vertexT, edgeT>
{
private:
    /** Матриця суміжності */
    vector<vector<Data<vertexT, edgeT>>> adjacencyMatrix;

    /** DFS обхід графа у вигляді матриці суміжності (допоміжна функція)
     * використовується як у алгоритмах, так і щоб показати граф.
     * Саме тому має додатковий параметр
     * bool print = false
     *
     * @param vertex - вершина для пошуку у глибину
     * @param visited - масив позначок відвіданих вершин
     * @param print - чи роздруковувати номери елементів графа при обході
     */
    void DFSUtil(Data<vertexT, edgeT> vertex, std::vector<bool> &visited, bool print = false)
    {
        // Відвідуємо поточну вершину
        visited[vertex.number] = true;
        if (print)
        {
            cout << " " << vertex.number << " ";
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
    /** Конструктор для графа у вигляді матриці суміжності
     *
     * @param numberOfVertices - кількість вершин
     */
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

    /** Віртуальний деструктор графа у вигляді матриці суміжності
     * для коректної роботи з вказівниками на базовий клас */
    virtual ~MatrixGraph() = default;

    /** Додавання ребра для графа у вигляді матриці суміжності
     *
     * @param startVertex - початкова вершина ребра
     * @param endVertex - кінцева вершина ребра
     * @param vertexData - дані для збереження у вершині
     * @param edgeData - дані для збереження у ребрі
     */
    void addEdge(uint startVertex, uint endVertex, vertexT vertexData, edgeT edgeData) override
    {
        if (startVertex < this->numberOfVertices and endVertex < this->numberOfVertices)
        {
            Data<vertexT, edgeT> edge(vertexData, edgeData, endVertex);
            this->adjacencyMatrix[startVertex][endVertex] = edge;
        }
        else
        {
            cout << "CANNOT ADD THIS EDGE" << endl;
        }
    }

    /** Видалення ребра для графа у вигляді матриці суміжності
     *
     * @param startVertex - початкова вершина ребра
     * @param endVertex - кінцева вершина ребра
     */
    void removeEdge(uint startVertex, uint endVertex)
    {
        if (startVertex < this->numberOfVertices)
        {
            adjacencyMatrix[startVertex][endVertex] = Data<vertexT, edgeT>();
        }
        cout << "CANNOT REMOVE THIS EDGE" << endl;
    }

    /** Знайти транспонований граф у вигляді матриці суміжності
     *
     * @return - транспонований граф того ж типу даних
     */
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

    /** Перевірка зв'язності орієнтованого графа графа у вигляді матриці суміжності
     *
     * @return - true, якщо граф зв'язний та false, якщо граф НЕ зв'язний
     */
    bool isConnected() override
    {
        // Ні одна вершина ще не відвідана
        vector<bool> visited(this->numberOfVertices, false);

        // DFS перший раз
        for (int i = 0; i < this->numberOfVertices; ++i)
        {
            bool flag = true;
            for (int j = 0; j < this->numberOfVertices; ++j)
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
        for (int i = 0; i < this->numberOfVertices; ++i)
        {
            bool flag = true;
            for (int j = 0; j < this->numberOfVertices; ++j)
            {
                if (transposedGraph->adjacencyMatrix[i][j].number >= 0)
                {
                    DFSUtil(transposedGraph->adjacencyMatrix[i][j], visited);
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
        return true;
    }

    /** Знаходження відстані між двома вершинами графа у вигляді матриці суміжності
     *
     * @param startVertex - початкова вершина
     * @param endVertex - кінцева вершина
     * @return - найменшу кількість ребер між заданими вершинами
     */
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

    /** BFS обхід графа у вигляді матриці суміжності
     *
     * @param vertex - початкова вершина для обходу
     */
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
                break;
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
            cout << "Дані у вершині: " << w.vertexData.formatDateTime() << endl;
            cout << "Дані у ребрі: " << w.edgeData << endl;
            cout << "Номер вершини: "<< w.number << endl;
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

    /** DFS обхід графа у вигляді матриці суміжності  (функція виклику)
     *
     * @param vertex - початкова вершина для обходу
     */
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
                break;
            }
        }

        // Ні одна вершина ще не відвідана
        vector<bool> visited(this->numberOfVertices, false);
        DFSUtil(w, visited, true);
    }
};

#endif //OOOP_LAB1_MATRIXGRAPH_H
