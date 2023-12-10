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

Rational Addition(Rational a, Rational b);
int Nsd(int a, int b); // для скорочення дробу

using namespace std;

int main() {
    Rational first, second;
    int a, b, c, d;
    cout << "Enter first number (a/b): ";
    cin >> a >> b;
    if (b != 0) first.SetNumerator(a), first.SetDenominator(b);
    cout << "Enter second number (c/d): ";
    cin >> c >> d;
    if (d != 0) second.SetNumerator(c), second.SetDenominator(d);
    Rational answer = Addition(first, second);
    cout << answer.GetNumerator() << "/" << answer.GetDenominator();
    return 0;
}

Rational Addition(Rational a, Rational b)
{
    Rational ans;
    if (a.GetDenominator() == b.GetDenominator())
    {
        ans.SetNumerator(a.GetNumerator() + b.GetNumerator());
        ans.SetDenominator(a.GetDenominator());
    }
    else
    {
        ans.SetDenominator(a.GetDenominator() * b.GetDenominator());
        ans.SetNumerator(a.GetNumerator()*b.GetDenominator() + b.GetNumerator()*a.GetDenominator());
    }
    // скорочення дробу (не обов'язково)
    int nsd = Nsd(ans.GetDenominator(), ans.GetNumerator());
    if (nsd != 1)
    {
        ans.SetDenominator(ans.GetDenominator() / nsd);
        ans.SetNumerator(ans.GetNumerator() / nsd);
    }
    return ans;
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