# Лабораторна робота №1

#### Made by Ryan Goslenko

## Завдання:
### Список 1: структури даних та алгоритми.
#### 7. (****) Графи на основі списку суміжності, матриці суміжності (збереження даних у вершинах та ребрах графів). Додавання та видалення вершин/ребер. Перевірка на зв'язність графу. Визначення відстані між двома вершинами графу.
- Графи на основі списку суміжності, матриці суміжності.
  Реалізовано базовий `class Graph` та підкласи `class AdjListGraph` i `class MatrixGraph`
- Збереження даних у вершинах та ребрах графів реалізовано за допомогою `struct Data
  {
  public:
  vertexT vertexData;
  edgeT edgeData}`
- Додавання та видалення ребер `void addEdge(uint startVertex, uint endVertex, vertexT vertexData, edgeT edgeData)` і `void removeEdge(uint startVertex, uint endVertex)`
- Перевірка на зв'язність графу `bool isConnected()`
- Визначення відстані між двома вершинами графу `int findDistance(uint startVertex, uint endVertex)`

##### +* за інші алгоритми на графах
- Додано візуалізація обходів графу `void BFS(uint vertex)` i `void DFS(uint vertex)`
- Додано функцію віртуального транспонування графу `Graph<vertexT, edgeT>* getTransposed()`
### Список 2: класи для опису даних.
#### 9. (**) Інформація про дату (рік, місяць, день) та час (години, хвилини, секунди). Перевірка правильності дати та часу відповідно до григоріанського календаря. Арифметика моментів часу: різниця між двома моментами часу у заданих одиницях, додавання чи віднімання такої різниці до заданого моменту часу. Обчислення дня тижня для заданої дати.
- Інформація про дату (рік, місяць, день) та час (години, хвилини, секунди) `class DateTime`
- Перевірка правильності дати та часу відповідно до григоріанського календаря **РЕАЛІЗОВАНО ВИПРАВЛЕННЯ НЕКОРЕКТНИХ ВВЕДЕНЬ ДАТИ**. Дефолтний конструктор `DateTime ()` встановлює некоректний час для подальшої його перевірки за допомогою функції `bool isValid() const`. Створення самого об'єкту дати/часу реалізовано як на основі `time_t`, `struct tm` та введеній користувачем даті у вказаному форматі. Для останнього випадку конструктор `explicit DateTime (const string &value)` створює за допомогою метода `set` об'єкт типу `STime`, для якого потім здійснюється виклик методу `.get()` **який вже й займається обробкою помилок введення дати**. Наприклад введення дати з місяцем під номер 13 (місяців усього 12) призведе до збільшення лічильника років на 1 та зменшення кількості місяців у даті на 12.
- Різниця між двома моментами часу у заданих одиницях. Реалізовано за допомогою методів, які знаходять різницю у конкретних одиницях:

-      // Кількість мілісекунд між датами
       static long long int millisecondsBetween(const DateTime &date1, const DateTime &date2);

       // Кількість секунд між датами
       static int secondsBetween(const DateTime &date1, const DateTime &date2);

       // Кількість хвилин між датами
       static int minutesBetween(const DateTime &date1, const DateTime &date2);

       // Кількість годин між датами
       static int hoursBetween(const DateTime &date1, const DateTime &date2);

       // Кількість днів між датами
       static int daysBetween(const DateTime &date1, const DateTime &date2);

       // Кількість місяців між датами
       static int monthsBetween(const DateTime &date1, const DateTime &date2);

       // Кількість років між датами
       static int yearsBetween(const DateTime &date1, const DateTime &date2);
- також є можливість це зробити за допомогою перевантаженого оператора `DateTime& operator - (const DateTime &date);`
- Додавання чи віднімання такої різниці до заданого моменту часу. Існують функції до збільшення та зменшення дати певну кількість відповідних одиниць, окрім того, загальна функції збільшення дати `DateTime& decreaseBy(int seconds, int minutes, int hours, int days, int months, int years)` та зменшення `DateTime& increaseBy(int seconds, int minutes, int hours, int days, int months, int years)`
- Досить зручно додавати та віднімати дати за допомогою перевантажених операторів
-           DateTime& operator - (const DateTime &date);
            DateTime& operator + (const DateTime &date);
- Окрім того, реалізовані конструктор копій та перевантажені оператори присвоєння та порівняння.
-           DateTime& operator = (const DateTime &date) = default;
-
          friend bool operator == (const DateTime &date1, const DateTime &date2);
          friend bool operator < (const DateTime &date1, const DateTime &date2);
          friend bool operator != (const DateTime &date1, const DateTime &date2);
          friend bool operator <= (const DateTime &date1, const DateTime &date2);
          friend bool operator > (const DateTime &date1, const DateTime &date2);
          friend bool operator >= (const DateTime &date1, const DateTime &date2);
##### +* за обчислення додаткових параметрів, наприклад, номер тижня в місяці та в році
- Додано функції
-      // Отримати день року
       int getDayOfYear() const;

       // Отримати тиждень року
       int getWeekOfYear() const;
##### +* за альтернативні варіанти побудови дати та часу (наприклад, «перший вівторок листопада»)
- Реалізоване цілення розмаїття способів побудови дати:
-        // Створює об'єкт за UTC часом у SQL форматі опису дати
         // "2022-10-07 00:20:21.420"
         explicit DateTime (const string &value);

         // Створює об'єкт за календарним часом time_t
         explicit DateTime (const time_t &time);

         // Створює об'єкт за структурою часу tm
         explicit DateTime (const tm *time);
##### +* за підтримку часових зон
-        // Конвертує локальний час в UTC
         void toUTC();

         // Конвертує UTC в локальний час
         void fromUTC();
#### ЗАГАЛЬНА КІЛЬКІСТЬ * зірочок    - 10
#### ДОДАТКОВО РЕАЛІЗОВАНО:
- Документація Doxygen
- UNIT TESTS (із використанням <doctest.h>)