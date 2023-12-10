/*
 * Перевірити на планарність граф,
 * представлений структурою суміжності
 * використаний гамма-алгоритм
*/

#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
    map<Vertex,vector<Vertex>> Adj;
    Adj[Vertex{1}] = vector<Vertex>{Vertex{2},Vertex{5},Vertex{7}};
    Adj[Vertex{2}] = vector<Vertex>{Vertex{1},Vertex{3},Vertex{8}};
    Adj[Vertex{3}] = vector<Vertex>{Vertex{2},Vertex{4},Vertex{9}};
    Adj[Vertex{4}] = vector<Vertex>{Vertex{3},Vertex{5},Vertex{10}};
    Adj[Vertex{5}] = vector<Vertex>{Vertex{4},Vertex{6},Vertex{1}};
    Adj[Vertex{6}] = vector<Vertex>{Vertex{8},Vertex{5},Vertex{7}};
    Adj[Vertex{7}] = vector<Vertex>{Vertex{1},Vertex{6},Vertex{9}};
    Adj[Vertex{8}] = vector<Vertex>{Vertex{2},Vertex{6},Vertex{10}};
    Adj[Vertex{9}] = vector<Vertex>{Vertex{3},Vertex{7},Vertex{10}};
    Adj[Vertex{10}] = vector<Vertex>{Vertex{4},Vertex{8},Vertex{9}};
    Graph graph(Adj);
    bool isPlanar = graph.IsPlanar();
    cout << "Your graph is: "<< (isPlanar? "planar" : "not planar") << endl;
    return 0;
}
