#ifndef OOOP_LAB1_DATA_H
#define OOOP_LAB1_DATA_H

/** ------[ Структура для зберігання даних у вершинах графа ]------ */
template <typename vertexT, typename edgeT>
struct Data
{
public:
    int number {};
    vertexT vertexData;
    edgeT edgeData;
    /** Конструктори */
    explicit Data(vertexT vertexData, edgeT edgeData, uint number = 0);
    explicit Data(edgeT edgeData, uint number = 0);
    explicit Data();
};

/** Перевантажений оператор ==
 * Типи vertexT та edgeT також повинні мати компаратор
 *
 * @tparam vertexT - тип даних у вершинах
 * @tparam edgeT - тип даних у ребрах
 * @param data1 - перший об'єкт порівняння
 * @param data2 - другий об'єкт порівняння
 * @return - true, якщо елементи рівні, false у іншому випадку
 */
template <typename vertexT, typename edgeT>
inline bool operator == (const Data<vertexT, edgeT> &data1, const Data<vertexT, edgeT> &data2)
{
    return data1.number == data2.number
    && data1.vertexData == data2.vertexData
    && data1.edgeData == data2.edgeData;
}

/** Конструктор
 *
 * @tparam vertexT - тип даних у вершинах
 * @tparam edgeT - тип даних у ребрах
 * @param vertexData - дані для вершини
 * @param edgeData - дані для ребра
 * @param number - номер кінцевої вершини
 */
template <typename vertexT, typename edgeT>
Data<vertexT, edgeT>::Data(vertexT vertexData, edgeT edgeData, uint number)
{
    this->vertexData = vertexData;
    this->edgeData = edgeData;
    this->number = number;
}

/** Конструктор
 *
 * @tparam vertexT - тип даних у вершинах
 * @tparam edgeT - тип даних у ребрах
 * @param edgeData - дані для ребра
 * @param number - номер кінцевої вершини
 */
template <typename vertexT, typename edgeT>
Data<vertexT, edgeT>::Data(edgeT edgeData, uint number)
{
    this->edgeData = edgeData;
    this->number = number;
}

/** Конструктор (встановлює номером вершини -1)
 *
 * @tparam vertexT - тип даних у вершинах
 * @tparam edgeT - тип даних у ребрах
 */
template<typename vertexT, typename edgeT>
Data<vertexT, edgeT>::Data()
{
    this->number = -1;
}
#endif //OOOP_LAB1_DATA_H