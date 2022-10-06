#include "Source/AdjListGraph.h"
#include "Source/MatrixGraph.h"
#include "Source/DateTime.h"


using std::cout;
using std::cin;
using std::endl;

int main()
{
    int numberOfVertices = 4;

/*    AdjListGraph<int, float> adjList(numberOfVertices);
    Graph<int, float>& graph{adjList};*/

    MatrixGraph<int, float> matrix(numberOfVertices);
    Graph<int, float>& graph{matrix};

    graph.addEdge(0, 1, 100, 5.5);
    graph.addEdge(0, 2, 200, 1.2);
    graph.addEdge(1, 2, 50, 10.3);
    graph.addEdge(2, 0, 100, 42.69);
    graph.addEdge(2, 3, 200, 69.69);

    cout << "BSF: ";
    cout << "(Починаючи з вершини номер " << 2 << ")\n";
    graph.BFS(2);
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "DSF: ";
    cout << "(Починаючи з вершини номер " << 2 << ")\n";
    graph.DFS(2);
    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    if (graph.isConnected())
    {
        cout << "Граф зв'язний";
    }
    else
    {
        cout << "Граф НЕ зв'язний";
    }

    cout << endl;
    cout << std::endl;
    cout << "Відстань між " << 1 << " та " << 3 << " = " << graph.findDistance(1, 3);
    return 0;
}