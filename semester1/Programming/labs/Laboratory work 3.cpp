//11.	Задаються n пар чисел, які задають багатокутник без самоперетинів. Знайти його площу та периметр.

//Для обчислення площі використано "метод трикутників"
#include <cmath>
#include <iostream>
using namespace std;

class Point 
{
public:
    int x;
    int y;
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

float TriangleSquare(Point& A, Point& B, Point& C, float &perimeter);
float Distance(Point& A, Point& B);

float constside = 0;                                                                     
//для ефективнішого обчислення площі трикутників зберігаємо в зовнішню змінну одну з його сторін 
//кожна третя сторона трикутника буде першою стороною наступного трикутника, тому їх не обов'язково рахувати заново
int main()
{                                                                      
    const int n = 7;                                                                //вершини многокутника
    Point points[n]{ Point(0,0), Point(2,4), Point(6,5), Point(10,3), Point(11,-1), Point(7, -5), Point(3,4) };
    float perimeter = Distance(points[0], points[1]);        
    float square = 0;
                                                                                    //перебір трикутників
    for (int i = 1; i < n - 1; i++) {
        square += TriangleSquare(points[0], points[i], points[i + 1], perimeter);
    }
    //Для ефективнішого обчислення периметру використаємо той самий цикл й функцію, як і для площі
    //Кожну ітерацію будемо додавати до периметру сторону трикутника ВС, крім цього додамо довжину першої і останньої сторін многокутника
    perimeter += constside;
    cout << "Square: " << square << endl;
    cout << "Perimeter: " << perimeter << endl;
    return 0;
}

float TriangleSquare(Point& A, Point& B, Point& C, float& perimeter)
{
    float AB;
    if (constside)
    {
        AB = constside;
    }
    else
    {
        AB = Distance(A, B);
    }
    float BC = Distance(B, C);
    float AC = Distance(A, C);
    constside = AC;
    perimeter += BC;
    float p = (AB + BC + AC) / 2;                           //половина периметра
    return sqrt(p * (p - AB) * (p - BC) * (p - AC));        //Формула Герона
}

float Distance(Point& A, Point& B) 
{
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}
