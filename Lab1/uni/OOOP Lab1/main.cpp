#include <iostream>
#include <list>
#include <vector>
#include <stack>

using namespace std;

// Клас для графу, представленого структурою суміжності
template <typename T> class Graph
{
    // Кількість вершин
    int V {};

    // Вказівник на список суміжних вершин
    vector<list<T>> adj;
public:

    // Конструктор
    explicit Graph(int V);

    // Додавання ребра
    void addEdge(int v, int w);

    // BFS обхід
    void BFS(int s);

    // DFS обхід
    void DFS(int s);
};

template <typename T> Graph<T>::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

template <typename T>
void Graph<T>::addEdge(int v, int w)
{
    // Додати вершину w до списку v
    adj[v].push_back(w);
}

template <typename T> void Graph<T>::BFS(int s)
{
    // Ні одна вершина ще не відвідана
    vector<bool> visited;
    visited.resize(V,false);

    // Черга для BFS
    list<int> queue;

    // Відвідуємо поточний вузол та додаємо до черги
    visited[s] = true;
    queue.push_back(s);

    while(!queue.empty())
    {
        // Видалення вузла з черги
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Отримуємо всі суміжні вершини вилученої з черги вершини s.
        // Якщо сусідня вершина не відвідана,
        // відвідуємо її й додаємо до черги
        for (auto adjacent: adj[s])
        {
            if (!visited[adjacent])
            {
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    }
}

template <typename T> void Graph<T>::DFS(int s)
{
    // Ні одна вершина ще не відвідана
    vector<bool> visited(V, false);

    // Стек для DFS
    stack<int> stack;

    // Пушимо поточний вузол в чергу
    stack.push(s);

    while (!stack.empty())
    {
        // Видаляємо вершину зі стеку
        int v = stack.top();
        stack.pop();

        // Стек може містити одну й ту саму вершину двічі,
        // тому перевіряємо, чи була вершина відвідана раніше
        if (!visited[v])
        {
            cout << v << " ";
            visited[v] = true;
        }

        // Відвідуємо всі сусідні вершини.
        // Якщо сусідня вершина не була відвідана, пушимо її до стеку
        for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if (!visited[*i])
            {
                stack.push(*i);
            }
        }
    }
}

int main()
{
    Graph<int> g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    const int s = 2;

    cout << "BST: ";
    cout << "(Починаючи з вершини номер " << s << ")\n";
    g.BFS(s);
    cout << endl;
    cout << "DST: ";
    cout << "(Починаючи з вершини номер " << s << ")\n";
    g.DFS(s);
    return 0;
}