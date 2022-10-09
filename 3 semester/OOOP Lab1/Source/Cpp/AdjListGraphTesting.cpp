#include "../Headers/doctest.h"
#include "../Headers/AdjListGraph.h"
#include "../Headers/MatrixGraph.h"

#include <list>
#include <vector>

/** Тестування AdjListGraph */

TEST_CASE("addEdge AdjListGraph testing")
{
    int numberOfVertices = 4;
    AdjListGraph<int, float> graph(numberOfVertices);

    graph.addEdge(0, 1, 100, 5.5);
    graph.addEdge(0, 2, 200, 1.2);
    graph.addEdge(1, 2, 100, 10.3);
    graph.addEdge(2, 0, 200, 42.69);
    graph.addEdge(2, 3, 100, 69.69);

    std::list<Data<int, float>> checkList;
    checkList.emplace_back(100, 5.5, 1);
    checkList.emplace_back(200, 1.2, 2);

    checkList.emplace_back(100, 10.3, 2);

    checkList.emplace_back(200, 42.69, 0);
    checkList.emplace_back(100, 69.69, 3);


    std::vector<list<Data<int, float>>> graphAdjList = graph.getAdjacencyList();
    auto it = checkList.begin();
    for (int v = 0; v < numberOfVertices; ++v)
    {
        for (Data<int, float> adjacent: graphAdjList[v])
        {
            REQUIRE(adjacent == *(it));
            ++it;
        }
    }
}

TEST_CASE("removeEdge MatrixGraph testing")
{
    int numberOfVertices = 2;
    AdjListGraph<int, float> graph(numberOfVertices);
    graph.addEdge(0, 1, 100, 5.5);
    graph.addEdge(1, 0, 200, 1.2);

    graph.removeEdge(0, 1);

    std::list<Data<int, float>> checkList;

    checkList.emplace_back(200, 1.2, 0);

    std::vector<list<Data<int, float>>> graphAdjList = graph.getAdjacencyList();
    auto it = checkList.begin();
    for (int v = 0; v < numberOfVertices; ++v)
    {
        for (Data<int, float> adjacent: graphAdjList[v])
        {
            REQUIRE(adjacent == *(it));
            ++it;
        }
    }
}