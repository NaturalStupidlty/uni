#include <vector>
#include <map>

using namespace std;

struct Vertex
{
    int number;

    bool operator<(const Vertex& r)const
    {
        return number<r.number;
    }

    bool operator==(const Vertex& r)const
    {
        return number == r.number;
    }

    bool operator!=(const Vertex& r)const
    {
        return number != r.number;
    }
};

struct Segment
{
    vector<Vertex> SegmentVector;

    explicit Segment(vector<Vertex> elements)
    {
        SegmentVector = move(elements);
    }

    bool operator==(const Segment& r)const
    {
        vector<Vertex> sortedLeftOperand = SegmentVector;
        vector<Vertex> sortedRightOperand = r.SegmentVector;
        sort(sortedLeftOperand.begin(), sortedLeftOperand.end());
        sort(sortedRightOperand.begin(),sortedRightOperand.end());
        return sortedLeftOperand==sortedRightOperand;
    }

    bool operator!=(const Segment& r)const
    {
        return !((*this)==r);
    }

    Vertex& operator[](int i)
    {
        return SegmentVector[i];
    }
};

class Graph
{
public:
    // Геттер списку зв'язності графа
    map<Vertex,vector<Vertex>> Adj()
    {
        return AdjList;
    }

    Graph(map<Vertex,vector<Vertex>> adjList)
    {
        AdjList = move(adjList);
    }

    Graph()
    {
        AdjList = map<Vertex,vector<Vertex>>();
    }

    bool IsPlanar()
    {
        Graph cycle = GetCycle();
        return CheckPlanarity(cycle);
    }
private:
    // Сам список зв'язності графа
    map<Vertex,vector<Vertex>> AdjList;
    // Масив граней графа
    vector<vector<Vertex>> planes;
    // Цикл, знайдений для гамма-алгоритму
    Graph FindCycle(vector<Vertex> usedVertices, Vertex currVertex, Vertex parentVertex);
    Segment FindSegment(const Graph &cycle, Vertex currVertex, vector<Vertex> usedVertices);
    Graph GetCycle();
    Segment GetSegment(Graph cycle);
    bool CheckPlanarity(Graph cycle);
};

