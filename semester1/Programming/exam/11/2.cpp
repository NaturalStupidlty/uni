#include <iostream>

using namespace std;

struct ChessPosition {
private:
    int x;
    unsigned char y;
public:
    void SetX(int a) {x = a;}
    void SetY(unsigned char b) {y = b;}
    int GetX() const {return x;}
    unsigned char GetY() const {return y;}
};

int ChessToInt(unsigned char b); // якщо позицію коня вводять у "шахматному стилі", наприклад (B;3) або (f;2)
// то для зручності краще привести її до цифрового вигляду наприклад (2;3) або (6;2)
// саме для цього й використовується ця функція

bool QueenMove(ChessPosition p, ChessPosition s);

int main() {
    ChessPosition first, second;
    int x1, x2;
    unsigned char y1, y2;
    cout << "Enter current position of queen on board 8x8: ";
    cin >> y1 >> x1;
    cout << "Enter next position: ";
    cin >> y2 >> x2;
    first.SetX(x1), first.SetY(y1);
    second.SetX(x2), second.SetY(y2);
    if (QueenMove(first, second))
    {
        cout << "Yes, that's a queen move!";
    }
    else
    {
        cout << "No, you cannot move a queen like that! ";
    }
    return 0;
}

int ChessToInt(unsigned char b)
{
    int position;
    int symbol = (int)b;
    switch (symbol) {
        case 97:
            position = 1;
            break;

        case 98:
            position = 2;
            break;

        case 99:
            position = 3;
            break;

        case 100:
            position = 4;
            break;

        case 101:
            position = 5;
            break;

        case 102:
            position = 6;
            break;

        case 103:
            position = 7;
            break;

        case 104:
            position = 8;
            break;
        default:
            position = 1;
            break;
    }
    return position;
}

bool QueenMove(ChessPosition p, ChessPosition s)
{
    int x1 = p.GetX(), x2 = s.GetX(), y1 = ChessToInt(p.GetY()), y2 = ChessToInt(s.GetY());
    if (x1 == x2 || y1 == y2 || (abs(y2 - y1) == abs(x2 - x1)))
    {
        return true;
    }
    else
    {
        return false;
    }
}
