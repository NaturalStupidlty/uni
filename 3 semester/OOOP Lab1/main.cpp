#include <iostream>
#include <list>
#include <vector>

using namespace std;

// Структура для зберігання даних у вершинах графа
template <typename T1, typename T2> struct AdjListNode
{
public:
    T1 vertexData;
    int number {};
    T2 edgeData;
    // Конструктор
    explicit AdjListNode(T1 vertexData, T2 edgeData, int number = 0);
};

template <typename T1, typename T2> AdjListNode<T1, T2>::AdjListNode(T1 vertexData, T2 edgeData, int n)
{
    this->vertexData = vertexData;
    this->edgeData = edgeData;
    this->number = n;
}

// Клас для графу, представленого списком суміжності
template <typename T1, typename T2> class Graph
{
private:
    // Кількість вершин
    int V {};

    // Список суміжних вершин
    vector<list<AdjListNode<T1, T2>>> adj;

public:
    // Конструктор
    explicit Graph(int V = 1);

    // Додавання ребра
    void addEdge(int v, AdjListNode<T1, T2> w);

    // Додавання вершини
    void addVertex(list<AdjListNode<T1, T2>>);

    //
    bool isStronglyConnected();

    //
    bool isUnilaterallyConnected();

    // BFS обхід
    void BFS(AdjListNode<T1, T2> v);

    // DFS обхід (функція виклику)
    void DFS(AdjListNode<T1, T2> v);

    // DFS обхід (допоміжна функція)
    void DFSUtil(AdjListNode<T1, T2> v, vector<bool> &visited);
};

template <typename T1, typename T2> Graph<T1, T2>::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

template <typename T1, typename T2> void Graph<T1, T2>::addEdge(int v, AdjListNode<T1, T2> w)
{
    // Додати вершину w до списку v
    adj[v].push_back(w);
}

template <typename T1, typename T2> void Graph<T1, T2>::addVertex(list<AdjListNode<T1, T2>> l)
{
    this->V++;
    this->adj.resize(V);
    adj[V] = l;
}

template <typename T1, typename T2> bool Graph<T1, T2>::isStronglyConnected()
{
    for (int i = 0; i < adj.size(); ++i)
    {
        if (adj[i].empty())
        {
            return false;
        }
    }
    return true;
}

template <typename T1, typename T2> bool Graph<T1, T2>::isUnilaterallyConnected()
{
    bool unilaterally = false;
    int v = 0;
    for (int i = 0; i < adj.size(); ++i)
    {
        if (adj[i].empty())
        {
            v = i;
            unilaterally = true;
            break;
        }
    }
    if (unilaterally)
    {
        for (int i = 0; i < adj.size(); ++i)
        {
            for (auto it = adj[i].begin(); it != adj[i].end(); ++it)
            {
                if (it->number == v)
                {
                    return true;
                }
            }
        }
        return false;
    }
    return true;
}

template <typename T1, typename T2> void Graph<T1, T2>::BFS(AdjListNode<T1, T2> v)
{
    // Ні одна вершина ще не відвідана
    vector<bool> visited;
    visited.resize(V,false);

    // Черга для BFS
    list<AdjListNode<T1, T2>> queue;

    // Відвідуємо поточний вузол та додаємо до черги
    visited[v.number] = true;
    queue.push_back(v);

    while(!queue.empty())
    {
        // Видалення вузла з черги
        v = queue.front();
        cout << v.number << " - " << v.vertexData << " - " << v.edgeData << "    ";
        queue.pop_front();

        // Отримуємо всі суміжні вершини вилученої з черги вершини s.
        // Якщо сусідня вершина не відвідана,
        // відвідуємо її й додаємо до черги.
        for (AdjListNode<T1, T2> adjacent: adj[v.number])
        {
            if (!visited[adjacent.number])
            {
                visited[adjacent.number] = true;
                queue.push_back(adjacent);
            }
        }
    }
    cout << endl;
}

template <typename T1, typename T2> void Graph<T1, T2>::DFS(AdjListNode<T1, T2> v)
{
    // Ні одна вершина ще не відвідана
    vector<bool> visited(V, false);
    DFSUtil(v, visited);
}

template <typename T1, typename T2> void Graph<T1, T2>::DFSUtil(AdjListNode<T1, T2> v, vector<bool> &visited)
{
    // Відвідуємо поточну вершину
    visited[v.number] = true;
    cout << v.number << " - " << v.vertexData << " - " << v.edgeData << "    ";

    // Рекурсивно проходимо інші вершини
    for (AdjListNode<T1, T2> adjacent: adj[v.number])
    {
        if (!visited[adjacent.number])
        {
            DFSUtil(adjacent, visited);
        }
    }
}

int main()
{
    Graph<int, float> g(4);

    AdjListNode<int, float> v1(100, 5.5, 1);
    g.addEdge(0, v1);
    AdjListNode<int, float> v2(200, 1.2,  2);
    g.addEdge(0, v2);
    AdjListNode<int, float> v3(50, 10.3, 2);
    g.addEdge(1, v3);
    AdjListNode<int, float> v4(100, 42.69, 0);
    g.addEdge(2, v4);
    AdjListNode<int, float> v5(200, 69.69, 3);
    g.addEdge(2, v5);

    cout << "BST: ";
    cout << "(Починаючи з вершини номер " << v2.number << ")\n";
    g.BFS(v2);
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "DST: ";
    cout << "(Починаючи з вершини номер " << v2.number << ")\n";
    g.DFS(v2);

    cout << endl;
    if (g.isStronglyConnected())
    {
        printf("%s", "Graph is strongly connected");
    }
    else
    {
        printf("%s", "Graph is NOT strongly connected");
    }
    cout << endl;
    if (g.isUnilaterallyConnected())
    {
        printf("%s", "Graph is unilaterally connected");
    }
    else
    {
        printf("%s", "Graph is NOT unilaterally connected");
    }
    cout << endl;
    return 0;
}