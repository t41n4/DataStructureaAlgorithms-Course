
#include <iostream>
using namespace std;
struct Node
{
    int key;
    Node *pLeft, *pRight;
};
typedef Node *TREE;
void CreateTree(TREE &root)
{
    root = NULL;
}

Node *CreateNode(char x)
{
    Node *p = new Node;
    if (p != NULL)
    {
        p->key = x;
        p->pLeft = NULL;
        p->pRight = NULL;
    }
    return p;
}

TREE CreateTree(int *pre, int *in, int m, int n, int k, int l)
{
    int i;
    TREE root;
    if (l < k)
        return NULL;
    root = new Node;
    if (root != NULL)
    {
        root->key = pre[m];
        for (i = k; i <= l; i++)
            if (in[i] == pre[m])
                break;
        root->pLeft = CreateTree(pre, in, m + 1, n, k, i - 1);
        root->pRight = CreateTree(pre, in, m + i - k + 1, n, i + 1, l);
    }
    return root;
}

void NLR(TREE root)
{
    if (!root)
        return;
    cout << root->key << " ";
    NLR(root->pLeft);
    NLR(root->pRight);
}

void LNR(TREE root)
{
    if (!root)
        return;
    LNR(root->pLeft);
    cout << root->key << " ";
    LNR(root->pRight);
}
void countLeaf(TREE root, int &count)
{
    if (root == NULL)
        return;
    count++;
    Node *p = root;
    countLeaf(p->pLeft, count);
    countLeaf(p->pRight, count);
}
int sum(TREE root)
{
     if (root != NULL)
    {
        int a = sum(root->pLeft);
        int b = sum(root->pRight);
        return root->key + a + b;
    }
    return 0;
}
float average(TREE root)
{
   int Tong = sum(root);
    int dem = 0;
    countLeaf(root,dem);
    return Tong/(float)dem;
}
int main()
{
    int pre[] = {13, 8, 5, 2, 1, 4, 3, 7, 6, 11, 9, 10, 12, 21, 18, 15, 14, 17, 16, 20, 19, 26, 24, 22, 23, 25, 29, 28, 27, 31, 30, 33, 32};
    int in[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33};
    int n = 33;
    TREE root = CreateTree(pre, in, 0, n - 1, 0, n - 1);
    LNR(root);
    cout << endl;
    NLR(root);
    cout << endl;
    
    int count = 0;
    cout << "TBCCCCCCCCCCCC:   "<<average(root);
    system("pause");
    return 0;
}