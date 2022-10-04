#include "AdjListGraph.h"
#include "MatrixGraph.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int numberOfVertices = 4;

/*    AdjListGraph<int, float> adjList(numberOfVertices);
    Graph<int, float>& g{adjList};*/

    MatrixGraph<int, float> matrix(numberOfVertices);
    Graph<int, float>& g{matrix};

    g.addEdge(0, 1, 100, 5.5);
    g.addEdge(0, 2, 200, 1.2);
    g.addEdge(1, 2, 50, 10.3);
    g.addEdge(2, 0, 100, 42.69);
    g.addEdge(2, 3, 200, 69.69);

    cout << "BSF: ";
    cout << "(Починаючи з вершини номер " << 2 << ")\n";
    g.BFS(2);
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "DSF: ";
    cout << "(Починаючи з вершини номер " << 2 << ")\n";
    g.DFS(2);
    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    if (g.isConnected())
    {
        cout << "Граф зв'язний";
    }
    else
    {
        cout << "Граф НЕ зв'язний";
    }

    cout << endl;
/*    if (g.isUnilaterallyConnected())
    {
        cout << "Граф частково зв'язний";
    }
    else
    {
        cout << "Граф НЕ частково зв'язний";
    }*/
    cout << std::endl;
    cout << "Відстань між " << 1 << " та " << 3 << " = " << g.findDistance(1, 3);
    return 0;
}