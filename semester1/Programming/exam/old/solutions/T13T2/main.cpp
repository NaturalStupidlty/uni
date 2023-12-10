#include <iostream>
#include <cmath>

using namespace std;

struct Point {
private:
    double x, y, r;
    int angle;
public:
    void SetX(double a){x = a;}
    void SetY(double b){y = b;}
    void SetR(double c){r = c;}
    void SetAngle(int f){angle = f;}
    double GetX() const {return x;}
    double GetY() const {return y;}
    double GetR() const {return r;}
    int GetAngle() const {return angle;}
};

void FindPolarCoordinates(Point &point);

int main() {
    Point m;
    double x, y;
    cout << "Enter coordinates (x;y): ";
    cin >> x >> y;
    m.SetX(x);
    m.SetY(y);
    FindPolarCoordinates(m);
    cout << m.GetR() << endl;
    cout << m.GetAngle() << endl;
    return 0;
}
void FindPolarCoordinates(Point &point)
{
    // r = sqrt(x^2 + y^2)
    point.SetR(sqrt(point.GetX()*point.GetX() + point.GetY()*point.GetY()));
    // cos (f) = x/r
    double cos;
    cos = point.GetX() / point.GetR();
    // нехай значення кута треба повернути у градусах
    point.SetAngle(int (acos(cos) * 180.0 / M_PI));
}