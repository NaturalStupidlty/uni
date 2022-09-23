#include <iostream>
#include <list>
#include <vector>

using namespace std;

// структура для зберігання даних у вершинах графа
template <typename T> struct AdjListNode
{
public:
    T data;
    int number{};

    // Конструктор
    explicit AdjListNode(T data, int number = 0);
};

template <typename T> AdjListNode<T>::AdjListNode(T data, int n)
{
    this->data = data;
    this->number = n;
}

// Клас для графу, представленого структурою суміжності
template <typename T> class Graph
{
    // Кількість вершин
    int V{};

    // Список суміжних вершин
    vector<list<AdjListNode<T>>> adj;
public:

    // Конструктор
    explicit Graph(T V);

    // Додавання ребра
    void addEdge(int v, AdjListNode<T> w);

    // BFS обхід
    void BFS(AdjListNode<T> v);

    // DFS обхід (функція виклику)
    void DFS(AdjListNode<T> v);

    // DFS обхід (допоміжна функція)
    void DFSUtil(AdjListNode<T> v, vector<bool> &visited);
};

template <typename T> Graph<T>::Graph(T V)
{
    this->V = V;
    adj.resize(V);
}

template <typename T> void Graph<T>::addEdge(int v, AdjListNode<T> w)
{
    // Додати вершину w до списку v
    adj[v].push_back(w);
}

template <typename T> void Graph<T>::BFS(AdjListNode<T> v)
{
    // Ні одна вершина ще не відвідана
    vector<bool> visited;
    visited.resize(V,false);

    // Черга для BFS
    list<AdjListNode<T>> queue;

    // Відвідуємо поточний вузол та додаємо до черги
    visited[v.number] = true;
    queue.push_back(v);

    while(!queue.empty())
    {
        // Видалення вузла з черги
        v = queue.front();
        cout << v.number << " - " << v.data << "    ";
        queue.pop_front();

        // Отримуємо всі суміжні вершини вилученої з черги вершини s.
        // Якщо сусідня вершина не відвідана,
        // відвідуємо її й додаємо до черги.
        for (AdjListNode<T> adjacent: adj[v.number])
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

template <typename T> void Graph<T>::DFS(AdjListNode<T> v)
{
    // Ні одна вершина ще не відвідана
    vector<bool> visited(V, false);
    DFSUtil(v, visited);
}

template <typename T> void Graph<T>::DFSUtil(AdjListNode<T> v, vector<bool> &visited)
{
    // Відвідуємо поточну вершину
    visited[v.number] = true;
    cout << v.number << " - " << v.data << "    ";

    // Рекурсивно проходимо інші вершини
    for (AdjListNode<T> adjacent: adj[v.number])
    {
        if (!visited[adjacent.number])
        {
            DFSUtil(adjacent, visited);
        }
    }
}

int main()
{
    Graph<int> g(4);
    AdjListNode<int> v1(100, 1);
    g.addEdge(0, v1);
    AdjListNode<int> v2(200, 2);
    g.addEdge(0, v2);
    AdjListNode<int> v3(50, 2);
    g.addEdge(1, v3);
    AdjListNode<int> v4(100, 0);
    g.addEdge(2, v4);
    AdjListNode<int> v5(200, 3);
    g.addEdge(2, v5);

    cout << "BST: ";
    cout << "(Починаючи з вершини номер " << v2.number << ")\n";
    g.BFS(v2);
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "DST: ";
    cout << "(Починаючи з вершини номер " << v2.number << ")\n";
    g.DFS(v2);
    return 0;
}