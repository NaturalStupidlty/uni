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

Rational MaxRational(Rational array[], int size);
int Nsd(int a, int b); // найбільший спільний дільник
void Simplify(Rational &n);// для скорочення дробу

using namespace std;

int main() {
    const int size = 3;
    Rational array[size], answer;
    cout << "Enter array of rational numbers (a/b): ";
    for (int i = 0; i < size; i++)
    {
        int a, b;
        cin >> a >> b;
        if (b != 0)
        {
            array[i].SetNumerator(a);
            array[i].SetDenominator(b);
        }
    }
    answer = MaxRational(array, size);
    cout << answer.GetNumerator() << "/" << answer.GetDenominator();
    return 0;
}

Rational MaxRational(Rational array[], int size)
{
    Rational ans;
    ans.SetNumerator(array[0].GetNumerator());
    ans.SetDenominator(array[0].GetDenominator());
    Simplify(ans);
    int ansN = ans.GetNumerator(), ansD = ans.GetDenominator();
    for (int i = 0; i < size; i++)
    {
        Simplify(array[i]);
        int n = array[i].GetNumerator(), d = array[i].GetDenominator();
        if(n*ansD > ansN * d)
        {
            ans.SetNumerator(array[i].GetNumerator());
            ans.SetDenominator(array[i].GetDenominator());
        }
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