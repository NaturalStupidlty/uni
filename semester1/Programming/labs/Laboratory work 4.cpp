//6.	Для знаходження коренів рівняння  f(x)=0 реалізувати чисельні методи хорд та дихотомії. Порівняти швидкість їх наближення до кореня.

#include <iostream>
using namespace std;

double f(double x);              // функція, що задає р-ня
double dichotomy(double a, double b, double eps, double (*ptr)(double), int& dichotomyCounter);     
double bunch(double a, double b, double eps, double (*ptr)(double), int& bunchCounter);


int main()
{
    double eps, a, b;
    int dichotomyCounter = 1, bunchCounter = 1;       // лічильники
    cout << "Enter interval [a,b]: \n";
    cin >> a >> b;
    cout << "Enter epsilon: \n";
    cin >> eps;
    if (f(a) * f(b) > 0)
    {
        cout << "There is no zero intersection on this interval. ";
    }
    else 
    {
        cout << dichotomy(a, b, eps, f, dichotomyCounter) << endl << bunch(a, b, eps, f, bunchCounter) << endl;
    }
    cout << "Dichotomy method has been used " << dichotomyCounter << " times to find the root." << endl;
    cout << "Bunch method has been used " << bunchCounter << " times to find the root." << endl;
    return 0;
}

double f(double x)                              // визначення функції
{
    return 2 * x * x * x + x* x - 10 * x;
}

double dichotomy(double a, double b, double eps, double (*ptr)(double), int& dichotomyCounter)
{

    if (ptr(a) * ptr(b) < 0)
    {
        double c = (a + b) / 2;
        double fc = ptr(c);
        double fb = ptr(b);
        double fa = ptr(c);
        while (fabs(fc) > eps)
        {
            if (fc * fa < 0)
            {
                c = (a + b) / 2;
                fb = fc;
                fc = ptr(c);
                dichotomyCounter++;
            }
            else
            {
                fa = fc;
                fc = ptr(c);
                c = (a + b) / 2;
                dichotomyCounter++;
            }
        }
        return c;
    }
}

double bunch(double a, double b, double eps, double (*ptr)(double), int& bunchCounter)
{
    if (ptr(a) * ptr(b) < 0)
    {
        double c;
        double fb = ptr(b);
        double fa = ptr(a);
        while (fabs(fb - fa) > eps)
        {
            c = (fb * a - fa * b) / (fb - fa);
            double fc = ptr(c);
            if ((fa * fc) > 0)
            {
                a = c;
                fa = fc;
                bunchCounter++;
            }
            else
            {
                b = c;
                fb = fc;
                bunchCounter++;
            }
        }
        return c;
    }
}