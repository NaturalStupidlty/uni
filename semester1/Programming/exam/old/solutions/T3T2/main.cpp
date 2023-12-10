#include <iostream>

using namespace std;

struct ComplexMatrix {
private:
    static const int size = 3;
    float X[size][size], Y[size][size];
public:
    void SetX(float x, int i, int j)
    {
        X[i][j]= x;
    }
    void SetY(float y, int i, int j)
    {
        Y[i][j]= y;
    }
    float GetX(int i, int j) const {return X[i][j];}
    float GetY(int i, int j) const {return Y[i][j];}
};

void ComplexMatrixMultiply(ComplexMatrix x, ComplexMatrix y, ComplexMatrix &ans, int s);

int main() {
    const int size = 3;
    float A[size][size], B[size][size], C[size][size], D[size][size];
    ComplexMatrix x, y, ans;
    cout << "Enter A";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> A[i][j];
            x.SetX(A[i][j], i, j);
        }
    }
    cout << "Enter B";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> B[i][j];
            x.SetY(B[i][j], i, j);
        }
    }
    cout << "Enter C";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> C[i][j];
            y.SetX(C[i][j], i, j);
        }
    }
    cout << "Enter D";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> D[i][j];
            y.SetY(D[i][j], i, j);
        }
    }
    ComplexMatrixMultiply(x, y, ans, size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << ans.GetX(i, j) << " ";
            cout << "i" << "+" << ans.GetY(i, j) << " " << endl;
        }
    }
    return 0;
}

void ComplexMatrixMultiply(ComplexMatrix x, ComplexMatrix y, ComplexMatrix &ans, int s)
{
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            ans.SetX((x.GetX(i, j)*y.GetX(i,j) + x.GetY(i,j)*y.GetY(i,j)), i, j);
            ans.SetY((x.GetY(i, j)*y.GetX(i,j) + x.GetX(i,j)*y.GetY(i,j)), i, j);
        }
    }
}
