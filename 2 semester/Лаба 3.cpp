// бінарні дерева

#include <iostream>

using namespace std;

struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct Stack
{
    int size;
    int top;
    struct TreeNode* *array;
};

bool AreTreesEqual(TreeNode* first, TreeNode* second);
bool AreTreesIsomorphic(TreeNode* first, TreeNode* second);

void TreeInorderPrint(TreeNode* tree); // показати дерево (обхід зверху вниз)
void TreePostorderPrint(TreeNode* tree); // показати дерево (обхід знизу вверх)
void TreeSymmetricPrint(TreeNode* tree); // показати дерево (обхід у симетричному порядку)

void TreeInorderIterativePrint(TreeNode* tree);
void TreePostorderIterativePrint(TreeNode* tree);

TreeNode* NewNode(int data);
TreeNode * AddNode(int data, TreeNode *tree);
TreeNode* NewTree(); // створити довільне дерево

int main()
{
    cout << "Enter first tree (-1 to skip node): ";
    TreeNode* tree1 = NewTree();
    TreeNode* tree2 = NewTree();
    if (AreTreesEqual(tree1, tree2))
    {
        cout << "Trees are equal";
    }
    else
    {
        cout << "Trees are not equal";
    }
    cout << endl << "------------------------" << endl;
    if (AreTreesIsomorphic(tree1, tree2))
    {
        cout << "Trees are isomorphic";
    }
    else
    {
        cout << "Trees are not isomorphic";
    }
    return 0;
}

//  базові функції стеку

Stack* createStack(int size)
{
    Stack* stack = new Stack;
    stack->size = size;
    stack->top = -1;
    stack->array = new TreeNode*[size];
    return stack;
}

int isEmpty(Stack* stack)
{
    return stack->top == -1;
}

int isFull(Stack* stack)
{
    return stack->top - 1 == stack->size;
}

void push(Stack* stack, TreeNode* node)
{
    if (isFull(stack))
    {
        return;
    }
    stack->array[++stack->top] = node;
}

TreeNode* pop(Stack* stack)
{
    if (isEmpty(stack))
    {
        return nullptr;
    }
    return stack->array[stack->top--];
}

TreeNode* peek(Stack* stack)
{
    if (isEmpty(stack))
    {
        return nullptr;
    }
    return stack->array[stack->top];
}

// робота з деревами

// рівність

bool AreTreesEqual(TreeNode* first, TreeNode* second)
{
    if (!first && !second)
    {
        return true;
    }
    else if (!first or !second)
    {
        return false;
    }
    else
    {
        if (first->data == second->data
            && AreTreesEqual(first->left, second->left)
            && AreTreesEqual(first->right, second->right))
        {
            return true;
        }
    }
    return false;
}

// ізомрфізм

bool AreTreesIsomorphic(TreeNode* first, TreeNode* second)
{
    if (!first && !second)
    {
        return true;
    }
    else if (!first or !second or (first->data != second->data))
    {
        return false;
    }
    return (AreTreesIsomorphic(first->left, second->left)
            && AreTreesIsomorphic(first->right, second->right))
        or (AreTreesIsomorphic(first->left, second->right)
            && AreTreesIsomorphic(first->right, second->left));
}

// виведення (рекурсивне)

void TreeInorderPrint(TreeNode* tree)
{
    if (tree)
    {
        cout << tree->data << " ";
        TreeSymmetricPrint(tree->left);
        TreeSymmetricPrint(tree->right);
    }
}

void TreePostorderPrint(TreeNode* tree)
{
    if (tree)
    {
        TreeSymmetricPrint(tree->left);
        TreeSymmetricPrint(tree->right);
        cout << tree->data << " ";
    }
}

void TreeSymmetricPrint(TreeNode* tree)
{
    if (tree)
    {
        TreeSymmetricPrint(tree->left);
        cout << tree->data << " ";
        TreeSymmetricPrint(tree->right);
    }
}

void printCurrentLevel(TreeNode* tree, int level)
{
    if (!tree)
    {
        return;
    }
    if (level == 1)
    {
        cout << tree->data << " ";
    }
    else if (level > 1)
    {
        printCurrentLevel(tree->left, level - 1);
        printCurrentLevel(tree->right, level - 1);
    }
}

int height(TreeNode* tree);

void TreeLevelPrint(TreeNode * tree)
{
    int h = height(tree);
    int i;
    for (i = 1; i <= h; i++)
    {
        printCurrentLevel(tree, i);
    }
}

// виведення (ітеративне)

void TreeInorderIterativePrint(TreeNode* tree)
{
    Stack* s = createStack(INT_MAX);
    TreeNode* curr = tree;
    while (curr or !isEmpty(s))
    {
        while (curr)
        {
            push(s, curr);
            curr = curr->left;
        }
        curr = peek(s);
        pop(s);
        cout << curr->data << " ";
        curr = curr->right;
    }
}

void TreePostorderIterativePrint(TreeNode* tree)
{
    if (!tree)
    {
        return;
    }
    Stack* stack = createStack(INT_MAX);
    do
    {
        while (tree)
        {
            if (tree->right)
            {
                push(stack, tree->right);
            }
            push(stack, tree);
            tree = tree->left;
        }
        tree = pop(stack);
        if (tree->right && peek(stack) == tree->right)
        {
            pop(stack);
            push(stack, tree);
            tree = tree->right;
        }
        else
        {
            cout << tree->data << " ";
            tree = nullptr;
        }
    } while (!isEmpty(stack));
}

// допоміжні функції для работи з деревами

TreeNode* NewNode(int data)
{
    TreeNode* node = new TreeNode;
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

TreeNode* NewTree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return nullptr;
    }
    TreeNode* root = NewNode(d);
    root->left = NewTree();
    root->right = NewTree();
    return root;
}

TreeNode * AddNode(int data, TreeNode *tree)
{
    if (!tree)
    {
        tree = NewNode(data);
    }
    else if (data < tree->data)
    {
        tree->left = AddNode(data, tree->left);
    }
    else
    {
        tree->right = AddNode(data, tree->right);
    }
    return(tree);
}

int height(TreeNode* tree)
{
    if (!tree)
    {
        return 0;
    }
    else
    {
        int leftHeight = height(tree->left);
        int rightHeight = height(tree->right);
        if (leftHeight > rightHeight)
        {
            return (leftHeight + 1);
        }
        else
        {
            return (rightHeight + 1);
        }
    }
}