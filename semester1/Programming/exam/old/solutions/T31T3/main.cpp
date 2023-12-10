#include <iostream>

struct Rational
{
private:
    int numerator, denominator;
public:
    void SetNumerator(int x){numerator = x;}
    void SetDenominator(int y){denominator = y;}
    int GetNumerator() const {return numerator;}
    int GetDenominator() const {return denominator;}
};

void Simplify(Rational &n);// для скорочення дробу
int Nsd(int a, int b); // найбільший спільний дільник

using namespace std;

int main() {
    Rational number;
    cout << "Enter a rational number (a/b): ";
    int a, b;
    cin >> a >> b;
    if (b)
    {
        number.SetNumerator(a);
        number.SetDenominator(b);
    }
    else
    {
        cout << "Incorrect input";
        return 0;
    }
    Simplify(number);
    cout << number.GetNumerator() << "/" << number.GetDenominator();
    return 0;
}

void Simplify(Rational &n)
{
    // скорочення дробу
    int nsd = Nsd(n.GetDenominator(), n.GetNumerator());
    if (nsd != 1)
    {
        n.SetDenominator(n.GetDenominator() / nsd);
        n.SetNumerator(n.GetNumerator() / nsd);
    }
}

int Nsd(int a, int b)
{
    int c;
    while(b)
    {
        c = b;
        b = a % b;
        a = c;
    }
    return a;
}
