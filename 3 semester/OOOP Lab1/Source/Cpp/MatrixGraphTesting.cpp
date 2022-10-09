#include <list>
#include <vector>
#include "../Headers/MatrixGraph.h"
#include "../Headers/doctest.h"

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
            if (graph[i][j].number != -1)
            {
                REQUIRE(graph[i][j] == matrixCheck[i][j]);
            }
        }
    }
}

TEST_CASE("removeEdge MatrixGraph testing")
{
    int numberOfVertices = 2;
    MatrixGraph<int, float> graph(numberOfVertices);
    graph.addEdge(0, 1, 100, 5.5);
    graph.addEdge(1, 0, 200, 1.2);

    graph.removeEdge(0, 1);

    std::vector<std::vector<Data<int, float>>> matrixCheck;

    std::vector<Data<int, float>> line1Check;
    line1Check.emplace_back(0,0, -1);
    line1Check.emplace_back(0,0, -1);

    std::vector<Data<int, float>> line2Check;
    line2Check.emplace_back(200,1.2, 0);
    line2Check.emplace_back(0,0, -1);

    matrixCheck.push_back(line1Check);
    matrixCheck.push_back(line2Check);

    for (int i = 0; i < numberOfVertices; ++i)
    {
        for (int j = 0; j < numberOfVertices; ++j)
        {
            if (graph[i][j].number != -1)
            {
                REQUIRE(graph[i][j] == matrixCheck[i][j]);
            }
        }
    }
}

TEST_CASE("isConnected MatrixGraph testing")
{
    int numberOfVertices = 4;
    MatrixGraph<std::string, float> matrix(numberOfVertices);
    Graph<std::string, float>& graph{matrix};

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

TEST_CASE("isConnected MatrixGraph testing")
{
    int numberOfVertices = 7;
    MatrixGraph<double, float> graph(numberOfVertices);

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