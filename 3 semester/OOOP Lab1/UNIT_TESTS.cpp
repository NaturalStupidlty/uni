#include "Source/Headers/doctest.h"

#include "Source/Headers/DateTime.h"

#include "Source/Headers/Graph.h"
#include "Source/Headers/AdjListGraph.h"
#include "Source/Headers/MatrixGraph.h"

#include <list>
#include <vector>

/** Тестування DateTime */


/** Тестування Graph */

/** Тестування MatrixGraph */

TEST_CASE("addEdge MatrixGraph testing")
{
    int numberOfVertices = 4;
    MatrixGraph<int, float> graph(numberOfVertices);

    graph.addEdge(0, 1, 100, 5.5);
    graph.addEdge(0, 2, 200, 1.2);
    graph.addEdge(1, 2, 100, 10.3);
    graph.addEdge(2, 0, 200, 42.69);
    graph.addEdge(2, 3, 100, 69.69);

    std::vector<std::vector<Data<int, float>>> matrixCheck;

    std::vector<Data<int, float>> line1Check;
    line1Check.emplace_back(0, 0, -1);
    line1Check.emplace_back(100, 5.5, 1);
    line1Check.emplace_back(200, 1.2, 2);
    line1Check.emplace_back(0, 0, -1);

    std::vector<Data<int, float>> line2Check;
    line2Check.emplace_back(0, 0, -1);
    line2Check.emplace_back(0, 0, -1);
    line2Check.emplace_back(100, 10.3, 2);
    line2Check.emplace_back(0, 0, -1);

    std::vector<Data<int, float>> line3Check;
    line3Check.emplace_back(200, 42.69, 0);
    line3Check.emplace_back(0, 0, -1);
    line3Check.emplace_back(0, 0, -1);
    line3Check.emplace_back(100, 69.69, 3);

    std::vector<Data<int, float>> line4Check;
    line4Check.emplace_back(0, 0, -1);
    line4Check.emplace_back(0, 0, -1);
    line4Check.emplace_back(0, 0, -1);
    line4Check.emplace_back(0, 0, -1);

    matrixCheck.push_back(line1Check);
    matrixCheck.push_back(line2Check);
    matrixCheck.push_back(line3Check);
    matrixCheck.push_back(line4Check);

    for (int i = 0; i < numberOfVertices; ++i)
    {
        for (int j = 0; j < numberOfVertices; ++j)
        {
            REQUIRE(graph[i][j] == matrixCheck[i][j]);
        }
    }
}

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
            CHECK(adjacent == *(it));
            ++it;
        }
    }
}
