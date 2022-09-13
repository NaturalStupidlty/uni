/*
 * Побудувати мінімальне кістякове дерево
 * для зв'язного неорієнтованого графа
 * методом Дейкстри-Пріма для графа
 * представленого структурою суміжності
*/

#include <iostream>

using namespace std;

struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
};

struct AdjList {
    struct AdjListNode* head;
};

// граф представлений структурою суміжності
struct Graph {
    int V;
    struct AdjList* array;
};

struct MinHeapNode {
    int v;
    int key;
};

// стуктура для роботи з множиною вершин графа
struct MinHeap {
    int size;
    int capacity;
    int* pos;
    struct MinHeapNode** array;
};

struct AdjListNode* newAdjListNode(int dest, int weight)
{
    AdjListNode* newNode = new AdjListNode;
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = nullptr;
    return newNode;
}

struct Graph* createGraph(int V)
{
    Graph* graph = new Graph;
    graph->V = V;
    graph->array = new AdjList[V];
    for (int i = 0; i < V; ++i)
    {
        graph->array[i].head = nullptr;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight)
{
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

struct MinHeapNode* newMinHeapNode(int v, int key)
{
    MinHeapNode* minHeapNode = new MinHeapNode;
    minHeapNode->v = v;
    minHeapNode->key = key;
    return minHeapNode;
}

struct MinHeap* createMinHeap(int capacity)
{
    MinHeap* minHeap = new MinHeap;
    minHeap->pos = new int[capacity];
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = new MinHeapNode*[capacity];
    return minHeap;
}

void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b)
{
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap* minHeap, int index)
{
    int smallest, left, right;
    smallest = index;
    left = 2 * index + 1;
    right = 2 * index + 2;

    if (left < minHeap->size
        && minHeap->array[left]->key < minHeap->array[smallest]->key)
    {
        smallest = left;
    }
    if (right < minHeap->size
        && minHeap->array[right]->key < minHeap->array[smallest]->key)
    {
        smallest = right;
    }
    if (smallest != index)
    {
        MinHeapNode* smallestNode = minHeap->array[smallest];
        MinHeapNode* idxNode = minHeap->array[index];
        minHeap->pos[smallestNode->v] = index;
        minHeap->pos[idxNode->v] = smallest;
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[index]);
        minHeapify(minHeap, smallest);
    }
}

bool isEmpty(MinHeap* minHeap)
{
    return minHeap->size == 0;
}

struct MinHeapNode* extractMin(MinHeap* minHeap)
{
    if (isEmpty(minHeap))
    {
        return nullptr;
    }
    MinHeapNode* root = minHeap->array[0];

    MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;
    minHeap->pos[root->v] = minHeap->size - 1;
    minHeap->pos[lastNode->v] = 0;
    --minHeap->size;
    minHeapify(minHeap, 0);
    return root;
}

void decreaseKey(MinHeap* minHeap, int v, int key)
{
    int i = minHeap->pos[v];
    minHeap->array[i]->key = key;
    while (i
        && minHeap->array[i]->key < minHeap->array[(i - 1) / 2]->key)
    {
        minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

bool isInMinHeap(MinHeap* minHeap, int v)
{
    if (minHeap->pos[v] < minHeap->size)
    {
        return true;
    }
    return false;
}

int* PrimMST(Graph* graph)
{
    int V = graph->V, key[V];
    int* parent = new int[V];
    struct MinHeap* minHeap = createMinHeap(V);
    for (int v = 1; v < V; ++v)
    {
        parent[v] = -1;
        key[v] = INT_MAX;
        minHeap->array[v] = newMinHeapNode(v, key[v]);
        minHeap->pos[v] = v;
    }
    key[0] = 0;
    minHeap->array[0] = newMinHeapNode(0, key[0]);
    minHeap->pos[0] = 0;
    minHeap->size = V;
    while (!isEmpty(minHeap))
    {
        MinHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v;
        struct AdjListNode* pCrawl = graph->array[u].head;
        while (pCrawl)
        {
            int v = pCrawl->dest;
            if (isInMinHeap(minHeap, v) && pCrawl->weight < key[v])
            {
                key[v] = pCrawl->weight;
                parent[v] = u;
                decreaseKey(minHeap, v, key[v]);
            }
            pCrawl = pCrawl->next;
        }
    }
    return parent;
}

int main()
{
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 2, 20);
    addEdge(graph, 1, 2, 30);
    addEdge(graph, 1, 3, 5);
    addEdge(graph, 2, 3, 15);
    addEdge(graph, 2, 4, 6);
    addEdge(graph, 3, 4, 8);

    int* parent = PrimMST(graph);
    cout << "Minimum spanning tree: ";
    for (int i = 1; i < V; ++i)
    {
        cout << i << " - " << parent[i] << endl;
    }
    return 0;
};