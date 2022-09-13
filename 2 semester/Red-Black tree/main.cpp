#include "RBT.h"

int main()
{
    RBTree bst;
    int input;
    cout << "Enter a sequence of numbers:  " << endl;
    cout << "(n > 0 -> add to the tree, n < 0 -> remove from the tree, n = 0 -> stop) " << endl;
    cin >> input;
    while (input)
    {
        if (input > 0)
        {
            bst.insertNode(abs(input));
        }
        else if (input < 0)
        {
            bst.deleteNode(abs(input));
        }
        bst.print();
        cin >> input;
    }
    return 0;
}