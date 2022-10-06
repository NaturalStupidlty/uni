#ifndef OOOP_LAB1_DATA_H
#define OOOP_LAB1_DATA_H

// Структура для зберігання даних у вершинах графа
template <typename vertexT, typename edgeT> struct Data
{
public:
    int number {};
    vertexT vertexData;
    edgeT edgeData;
    // Конструктор
    explicit Data(vertexT vertexData, edgeT edgeData, uint number = 0);
    explicit Data(edgeT edgeData, uint number = 0);
    explicit Data();
};

template <typename vertexT, typename edgeT> Data<vertexT, edgeT>::Data(vertexT vertexData, edgeT edgeData, uint n)
{
    this->vertexData = vertexData;
    this->edgeData = edgeData;
    this->number = n;
}

template <typename vertexT, typename edgeT> Data<vertexT, edgeT>::Data(edgeT edgeData, uint n)
{
    this->edgeData = edgeData;
    this->number = n;
}

template <typename vertexT, typename edgeT> Data<vertexT, edgeT>::Data()
{
    this->vertexData = 0;
    this->edgeData = 0;
    this->number = -1;
}

#endif //OOOP_LAB1_DATA_H