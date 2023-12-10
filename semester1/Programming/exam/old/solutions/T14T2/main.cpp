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

int ChessToInt(unsigned char a); // якщо позицію коня вводять у "шахматному стилі", наприклад (3;В) або (2;f)
// то для зручності краще привести її до цифрового вигляду наприклад (3;2) або (2;6)
// саме для цього й використовується ця функція

bool HorseMove(ChessPosition a, ChessPosition b);

int main() {
    ChessPosition first, second;
    int x1, x2;
    unsigned char y1, y2;
    cout << "Enter current position of horse on board 8x8: ";
    cin >> x1 >> y1;
    cout << "Enter next position: ";
    cin >> x2 >> y2;
    first.SetX(x1), first.SetY(y1);
    second.SetX(x2), second.SetY(y2);
    if (HorseMove(first, second))
    {
        cout << "Yes, that's a horse move!";
    }
    else
    {
        cout << "No, you cannot move a horse like that! ";
    }
    return 0;
}

int ChessToInt(unsigned char a)
{
    int position;
    int symbol = (int)a;
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

bool HorseMove(ChessPosition a, ChessPosition b)
{
    int x1 = a.GetX(), x2 = b.GetX(), y1 = ChessToInt(a.GetY()), y2 = ChessToInt(b.GetY());
    if (x1 + 2 == x2 && y1 + 1 == y2 || x1 + 1 == x2 && y1 + 2 == y2 || x1 - 1 == x2 && y1 + 2 == y2 || x1 - 2 == x2 && y1 + 1 == y2 || x1 - 2 == x2 && y1 - 1 == y2 || x1 - 1 == x2 && y1 - 2 == y2 || x1 + 1 == x2 && y1 - 2 == y2 || x1 + 2 == x2 && y1 - 1 == y2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
