#include <iostream>
#include <cmath>

using namespace std;

struct Point {
private:
    float x;
    float y;
public:
    void SetX(float a){x = a;}
    void SetY(float b){y = b;}
    float GetX() const {return x;}
    float GetY() const {return y;}
};

float MaxPerimeter(Point *points, int size, Point *&answer);
float Distance(Point p1, Point p2);  // відстань між двома точками

int main() {
    int n;
    cout << ("Enter how many points: ");
    cin >> n;
    Point *points = new Point[n];
    float x, y;
    cout << "Enter points: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        cin >> y;
        points[i].SetX(x);
        points[i].SetY(y);
    }
    Point *answer = new Point[3];
    cout << "Biggest perimeter: " << MaxPerimeter(points, n, answer) << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << answer[i].GetX() << " ";
        cout << answer[i].GetY() << endl;
    }
    delete[]points;
    delete[]answer;
    return 0;
}

float MaxPerimeter(Point *points, int size, Point *&answer)
{
    float ab, bc, ca, p = 0;
    //треба перебрати всі комбінації точок
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            ab = Distance(points[i], points[j]);
            for(int k = 0; k < size; k++)
            {
                bc = Distance(points[j], points[k]);
                ca = Distance(points[k], points[i]);
                if(ab + bc + ca > p)
                {
                    p = ab + bc + ca;
                    answer[0].SetX(points[i].GetX());
                    answer[0].SetY(points[i].GetY());

                    answer[1].SetX(points[j].GetX());
                    answer[1].SetY(points[j].GetY());

                    answer[2].SetX(points[k].GetX());
                    answer[2].SetY(points[k].GetY());
                }
            }
        }
    }
    return p;
}
