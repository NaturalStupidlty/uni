#include <iostream>

#define RED true
#define BLACK false

using namespace std;

// представлення вузла в дереві

typedef struct Node
{
    int data;
    bool color;
    Node *parent;
    Node *left;
    Node *right;
} *NodePtr;

// клас дерев, у якому інкапсульовані всі методи для роботи з ними

class RBTree {
public:
    RBTree()
    {
        TreeNull = new Node;
        TreeNull->color = BLACK;
        TreeNull->left = nullptr;
        TreeNull->right = nullptr;
        root = TreeNull;
    }

    // додавання елементу

    void insertNode(int key)
    {
        // звичайне додавання вузла
        auto node = new Node;
        node->parent = nullptr;
        node->data = key;
        node->left = TreeNull;
        node->right = TreeNull;
        node->color = RED; // новий вузол завжди червоний

        NodePtr y = nullptr;
        NodePtr x = this->root;

        while (x != TreeNull)
        {
            y = x;
            if (node->data < x->data)
            {
                x = x->left;
            }
            else
            {
                x = x->right;
            }
        }

        // y батько x
        node->parent = y;
        if (!y)
        {
            root = node;
        }
        else if (node->data < y->data)
        {
            y->left = node;
        }
        else
        {
            y->right = node;
        }

        // якщо новий вузол кореневий
        if (!node->parent)
        {
            node->color = BLACK;
            return;
        }

        // якщо дідусь вузла нульовий
        if (!node->parent->parent)
        {
            return;
        }

        fixInsert(node);
    }

    // вилучення

    void deleteNode(int data)
    {
        deleteNodeHelper(this->root, data);
    }

    // ліве обертання

    void leftRotate(NodePtr x)
    {
        NodePtr y = x->right;
        x->right = y->left;
        if (y->left != TreeNull)
        {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (!x->parent)
        {
            this->root = y;
        }
        else if (x == x->parent->left)
        {
            x->parent->left = y;
        }
        else
        {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    // праве обертання

    void rightRotate(NodePtr x)
    {
        NodePtr y = x->left;
        x->left = y->right;
        if (y->right != TreeNull)
        {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (!x->parent)
        {
            this->root = y;
        }
        else if (x == x->parent->right)
        {
            x->parent->right = y;
        }
        else
        {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

    // мінімальний елемент (для вилучення)

    NodePtr minimum(NodePtr node)
    {
        while (node->left != TreeNull)
        {
            node = node->left;
        }
        return node;
    }

    // показати дерево

    void print()
    {
        if (root)
        {
            printHelper(this->root, "", true);
        }
    }

private:
    NodePtr root;
    NodePtr TreeNull;

    // допоміжні функції

    void deleteNodeHelper(NodePtr node, int key)
    {
        // пошук елемента
        NodePtr z = TreeNull;
        NodePtr x, y;
        while (node != TreeNull)
        {
            if (node->data == key)
            {
                z = node;
            }
            if (node->data <= key)
            {
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }
        if (z == TreeNull)
        {
            cout << "Could not find the key in the tree :( " << endl;
            return;
        }

        y = z;
        int y_original_color = y->color;
        if (z->left == TreeNull)
        {
            x = z->right;
            rbTransplant(z, z->right);
        }
        else if (z->right == TreeNull)
        {
            x = z->left;
            rbTransplant(z, z->left);
        }
        else
        {
            y = minimum(z->right);
            y_original_color = y->color;
            x = y->right;
            if (y->parent == z)
            {
                x->parent = y;
            }
            else
            {
                rbTransplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            rbTransplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;
        if (!y_original_color)
        {
            fixDelete(x);
        }
    }

    void printHelper(NodePtr tree, string indent, bool last)
    {
        if (tree != TreeNull)
        {
            cout << indent;
            if (last)
            {
                cout << "R ---- ";
                indent += "     ";
            }
            else
            {
                cout << "L ---- ";
                indent += "|    ";
            }
            if (tree->color == RED)
            {
                cout << tree->data  << " " << "\033[31m" << "RED" << "\033[0m" << " " << endl;
            }
            else
            {
                cout << tree->data  << " " << "\033[3;100;30m" << "BLACK" << "\033[0m" << " " << endl;
            }
            printHelper(tree->left, indent, false);
            printHelper(tree->right, indent, true);
        }
    }

    // обмін кольорами

    void rbTransplant(NodePtr u, NodePtr v)
    {
        if (!u->parent)
        {
            root = v;
        }
        else if (u == u->parent->left)
        {
            u->parent->left = v;
        }
        else
        {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    // виправити можливі порушення

    void fixDelete(NodePtr x)
    {
        NodePtr s;
        while (x != root && x->color == BLACK)
        {
            if (x == x->parent->left)
            {
                s = x->parent->right;
                if (s->color == RED)
                {
                    // Випадок 3.1 брат S червоний
                    s->color = BLACK;
                    x->parent->color = RED;
                    leftRotate(x->parent);
                    s = x->parent->right;
                }

                if (s->left->color == BLACK && s->right->color == BLACK)
                {
                    // Випадок 3.2: брат S чорний і всі діти S чорні
                    s->color = RED;
                    x = x->parent;
                }
                else
                {
                    if (s->right->color == BLACK)
                    {
                        // Випадок 3.3: брат S чорний і права дитина S чорна, а ліва - червона
                        s->left->color = BLACK;
                        s->color = RED;
                        rightRotate(s);
                        s = x->parent->right;
                    }

                    // Випадок 3.4: брат S чорний і права дитина S червона
                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->right->color = RED;
                    leftRotate(x->parent);
                    x = root;
                }
            }
                // Дзеркальне відображення
            else
            {
                s = x->parent->left;
                if (s->color == RED)
                {
                    // Випадок 3.1
                    s->color = BLACK;
                    x->parent->color = RED;
                    rightRotate(x->parent);
                    s = x->parent->left;
                }

                if (s->right->color == BLACK && s->left->color == BLACK)
                {
                    // Випадок 3.2
                    s->color = RED;
                    x = x->parent;
                }
                else
                {
                    if (s->left->color == BLACK)
                    {
                        // Випадок 3.3
                        s->right->color = BLACK;
                        s->color = RED;
                        leftRotate(s);
                        s = x->parent->left;
                    }
                    // Випадок 3.4
                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->left->color = BLACK;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

    void fixInsert(NodePtr k)
    {
        NodePtr u;
        while (k->parent->color == RED)
        {
            if (k->parent == k->parent->parent->right)
            {
                u = k->parent->parent->left; // дядько
                if (u->color == RED)
                {
                    // Випадок 3.1: P червоний і U теж червоний.
                    // У цьому випадку ми перевертаємо колір вузлів P, U і G
                    // Це означає, що P стає чорним, U стає чорним і, G стає червоним.
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                }
                    // Випадок 3.2: P червоний і U чорний (або NULL)
                else
                {
                    if (k == k->parent->left)
                    {
                        // Випадок 3.2.2: P є правою дитиною G і К є лівою дитиною P
                        // Зводиться до випадку 3.2.1
                        k = k->parent;
                        rightRotate(k);
                    }
                    // Випадок 3.2.1: P є правою дитиною G і К є правою дитиною P
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    leftRotate(k->parent->parent);
                }
            }
                // Дзеркальне відображення
            else
            {
                u = k->parent->parent->right; // дядько

                if (u->color == RED)
                {
                    // Випадок 3.1:
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                }
                else
                {
                    if (k == k->parent->right)
                    {
                        // Випадок 3.2.2
                        k = k->parent;
                        leftRotate(k);
                    }
                    // Випадок 3.2.1
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    rightRotate(k->parent->parent);
                }
            }
            if (k == root)
            {
                break;
            }
        }
        root->color = BLACK;
    }

};
