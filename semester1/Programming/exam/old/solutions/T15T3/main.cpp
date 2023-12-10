#include <iostream>

using namespace std;

struct Domino
{
private:
    int up;
    int down;
public:
    void SetUp(int a){up = a;}
    void SetDown(int b){down = b;}
    int GetUp() const {return up;}
    int GetDown() const {return down;}
};

bool Correct(Domino *r);
bool Repeat(Domino *r, int end); // окремо винесемо перевірку, чи зустрічалася кістка доміно раніше

int main() {
    const int dominoesNumber = 22;
    Domino sequence[dominoesNumber];
    Domino * r = sequence;
    cout << "Enter dominoes: ";
    for (int i = 0; i < dominoesNumber; i++)
    {
        int a, b;
        cin >> a >> b;
        if ( a < 7 && b < 7 && a >= 0 && b >= 0)
        {
            r[i].SetUp(a), r[i].SetDown(b);
        }
        else
        {
            cout << "Incorrect input";
            return 0;
        }
    }
    if(Correct(r))
    {
        cout << "It is right!";
    }
    else
    {
        cout << "It is wrong :(";
    }
    return 0;
}

bool Correct(Domino *r)
{
    for (int i = 1; i < 22; i++)
    {
        if (r[i].GetUp() == r[i-1].GetDown())
        {
            if(!Repeat(r, i))
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool Repeat (Domino *r, int end)
{
    for (int j = 0; j < end; j++)
    {
        if((r[end].GetDown() == r[j].GetDown()) && (r[end].GetUp() == r[j].GetUp()))
        {
            return false;
        }
        else if ((r[end].GetUp() == r[j].GetDown()) && (r[end].GetDown() == r[j].GetUp()))
        {
            return false;
        }
    }
    return true;
}