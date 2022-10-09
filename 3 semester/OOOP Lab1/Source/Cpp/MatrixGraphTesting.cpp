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
            REQUIRE(graph[i][j] == matrixCheck[i][j]);
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
            REQUIRE(graph[i][j] == matrixCheck[i][j]);
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