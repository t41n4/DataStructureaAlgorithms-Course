struct Node
{
    int data;
    int *pleft;
    int *pright;
};

struct Tree
{
    Node* root = NULL;
};
