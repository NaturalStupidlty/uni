#include "../Headers/doctest.h"
#include "../Headers/AdjListGraph.h"

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

TEST_CASE("removeEdge AdjListGraph testing")
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

TEST_CASE("isConnected AdjListGraph testing")
{
    int numberOfVertices = 4;
    AdjListGraph<std::string, float> graph(numberOfVertices);

    std::string string1 = "one";
    std::string string2 = "two";
    std::string string3 = "three";
    std::string string4 = "four";

    graph.addEdge(0, 1, string1, 5.5);
    graph.addEdge(0, 2, string3, 1.2);
    graph.addEdge(1, 2, string3, 10.3);
    graph.addEdge(2, 0, string1, 42.69);
    graph.addEdge(2, 3, string4, 69.69);

    CHECK(graph.isConnected());
}

TEST_CASE("isConnected AdjListGraph testing")
{
    int numberOfVertices = 7;
    AdjListGraph<double, float> graph(numberOfVertices);

    graph.addEdge(0, 1, 44, 1);
    graph.addEdge(0, 2, 33, 2);
    graph.addEdge(0, 4, 22, 4);

    graph.addEdge(1, 2, 55, 1);
    graph.addEdge(1, 0, 66, 1);

    graph.addEdge(2, 0, 11, 2);
    graph.addEdge(2, 5, 22, 3);
    graph.addEdge(2, 1, 23, 1);

    graph.addEdge(3, 4, 88, 1);

    graph.addEdge(4, 0, 44, 4);
    graph.addEdge(4, 3, 33, 1);
    graph.addEdge(4, 5, 22, 1);
    graph.addEdge(4, 6, 22, 2);

    graph.addEdge(5, 4, 11, 1);
    graph.addEdge(5, 2, 22, 3);

    graph.addEdge(6, 4, 99, 2);

    CHECK(graph.findDistance(1, 5) == 2);
}

TEST_CASE("getTransposed AdjListGraph testing")
{
    int numberOfVertices = 4;
    AdjListGraph<double, float> graph(numberOfVertices);

    graph.addEdge(0, 1, 1, 5.5);
    graph.addEdge(0, 2, 2, 1.2);
    graph.addEdge(1, 2, 3, 10.3);
    graph.addEdge(2, 0, 4, 42.69);
    graph.addEdge(2, 3, 5, 69.69);

    AdjListGraph<double, float>* transposedGraph = graph.getTransposed();

    std::list<Data<double, float>> checkList;
    checkList.emplace_back(Data<double, float>(1, 5.5, 1));
    checkList.emplace_back(Data<double, float>(2, 1.2, 2));
    checkList.emplace_back(Data<double, float>(3, 10.3, 2));
    checkList.emplace_back(Data<double, float>(4, 42.69, 0));
    checkList.emplace_back(Data<double, float>(5, 69.69, 3));

    std::vector<list<Data<double, float>>> graphAdjList = graph.getAdjacencyList();
    auto it = checkList.begin();
    for (int v = 0; v < numberOfVertices; ++v)
    {
        for (Data<double, float> adjacent: graphAdjList[v])
        {
            REQUIRE(adjacent == *(it));
            ++it;
        }
    }
}