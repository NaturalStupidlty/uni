#ifndef OOOP_LAB1_GRAPH_H
#define OOOP_LAB1_GRAPH_H

#include <iostream>

/** ------[ Базовий клас графа ]------ */
template <typename vertexT, typename edgeT>
class Graph
{
protected:
    /** Кількість вершин */
    uint numberOfVertices{};

    /** Конструктор базового класу
     *
     * @param numberOfVertices - кількість вершин
     */
    explicit Graph(uint numberOfVertices = 1)
    {;
        if (numberOfVertices > 0)
        {
            this->numberOfVertices = numberOfVertices;
        }
        else
        {
            std::cout << "CANNOT CREATE THIS KIND OF A GRAPH" << std::endl;
        }
    }

    /** Віртуальний деструктор для коректної
     * роботи з вказівниками на базовий клас */
    virtual ~Graph() = default;

public:
    /** Додавання ребра
     *
     * @param startVertex - початкова вершина ребра
     * @param endVertex - кінцева вершина ребра
     * @param vertexData - дані для збереження у вершині
     * @param edgeData - дані для збереження у ребрі
     */
    virtual void addEdge(uint startVertex, uint endVertex, vertexT vertexData, edgeT edgeData) = 0;

    /** Видалення ребра
     *
     * @param startVertex - початкова вершина ребра
     * @param endVertex - кінцева вершина ребра
     */
    virtual void removeEdge(uint startVertex, uint endVertex) = 0;

    /** Знайти транспонований граф
     *
     * @return - транспонований граф того ж типу даних
     */
    virtual Graph<vertexT, edgeT>* getTransposed() = 0;

    /** Перевірка зв'язності орієнтованого графа
     *
     * @return - true, якщо граф зв'язний та false, якщо граф НЕ зв'язний
     */
    virtual bool isConnected() = 0;

    /** Знаходження відстані між двома вершинами
     *
     * @param startVertex - початкова вершина
     * @param endVertex - кінцева вершина
     * @return - найменшу кількість ребер між заданими вершинами
     */
    virtual int findDistance(uint startVertex, uint endVertex) = 0;

    /** BFS обхід
     *
     * @param vertex - початкова вершина для обходу
     */
    virtual void BFS(uint vertex) = 0;

    /** DFS обхід (функція виклику)
     *
     * @param vertex - початкова вершина для обходу
     */
    virtual void DFS(uint vertex) = 0;
};

#endif //OOOP_LAB1_GRAPH_H
