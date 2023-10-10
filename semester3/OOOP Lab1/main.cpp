#include "Source/Headers/AdjListGraph.h"
#include "Source/Headers/MatrixGraph.h"
#include "Source/Headers/DateTime.h"

#define DOCTEST_CONFIG_IMPLEMENT
#include "Source/Headers/doctest.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char** argv)
{
    doctest::Context context;
    context.applyCommandLine(argc, argv);
    int res = context.run();
    if(context.shouldExit())
    {
        return res;
    }

    DateTime time1;
    time1.setNow();
    cout << "UTC час зараз: " << endl;
    cout << time1.formatDateTime() << endl;
    time1.fromUTC();
    cout << "Локальний час зараз: " << endl;
    cout << time1.formatDateTime() << endl;
    cout << time1.getWeekOfYear() << endl;

    DateTime time2 = time1.increaseBy(69, 420, 666, 0, 0 ,0);
    DateTime time3 = time1.decreaseByMonths(13);
    DateTime time4("2022-10-07 00:20:21.420");

    DateTime time66("2022-10-10 00-36-55");
    DateTime time77 = time66.decreaseByHours(3);
    time66.toUTC();
    cout << time66.formatDateTime() << " " << time77.formatDateTime() << " "<< endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    int numberOfVertices = 4;

    MatrixGraph<DateTime, float> matrix(numberOfVertices);
    Graph<DateTime, float>& graph{matrix};

    graph.addEdge(0, 1, time2, 5.5);
    graph.addEdge(0, 2, time3, 1.2);
    graph.addEdge(1, 2, time3, 10.3);
    graph.addEdge(2, 0, time1, 42.69);
    graph.addEdge(2, 3, time4, 69.69);

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
