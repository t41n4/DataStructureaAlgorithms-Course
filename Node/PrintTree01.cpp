#include <bits/stdc++.h>
using namespace std;
   struct TreeNode
{
    TreeNode *left = NULL;
    TreeNode *right = NULL;
    int val = 0;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class TemplateBST
{
private:
 
public:
    
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == NULL)
        return NULL;
    if (key > root->val)
        root->right = deleteNode(root->right, key);
    else if (key < root->val)
        root->left = deleteNode(root->left, key);
    else
        root = removeNode(root);
    return root;
}
TreeNode *removeNode(TreeNode *root)
{
    //nếu node cần xoá là node đơn
    if (root->left == NULL && root->right == NULL)
        return NULL;
    //nếu node cần xoá là node với node->left = NULL
    else if (root->left == NULL)
        return root->right;
    //nếu node cần xoá là node với node->right = NULL
    else if (root->right == NULL)
        return root->left;
    // trường hợp còn lại (root->left != NULL && root->right != NULL)
    else
    {
        TreeNode *temp;
        temp = root->right;
        //Tìm Node Bé nhất
        while (temp->left != NULL)
        {
            temp = temp->left;
        }

        temp->left = root->left;
        return root->right;
    }
}
void prettyPrintTree(TreeNode *node, string prefix = "", bool isLeft = true)
{
    if (node == nullptr)
    {
        cout << "Empty tree";
        return;
    }

    if (node->right)
        prettyPrintTree(node->right, prefix + (isLeft ? "|   " : "    "), false);

    cout << prefix + (isLeft ? "|,," : "|''") + to_string(node->val) + "\n";

    if (node->left)
        prettyPrintTree(node->left, prefix + (isLeft ? "    " : "|   "), true);
}

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch)
                                       { return !isspace(ch); }));
}
void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch)
                        { return !isspace(ch); })
                    .base(),
                input.end());
}
TreeNode *stringToTreeNode(string input)
{
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size())
    {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode *root = new TreeNode(stoi(item));
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (true)
    {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ','))
        {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null")
        {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ','))
        {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null")
        {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}
float random(float min, float max)
	{
		float scale = rand() / (float)RAND_MAX; 
		return min + scale * (max - min);      
	}
string randomarray()
{
    string res;
    cout << "Nhap So Luong Node";
    int p;
    cin>>p;
    res = "[";
    for (int i = 0; i < p; i++)
    {
      res = res + to_string(int(random(5,50)))+",";
    }
    res += "]";
    res.erase(res.end()-2);
    return res;
}

void TravelsalNLR_(TreeNode* root)
{
    if (!root) return ;
    cout << root->val<<" ";
    TravelsalNLR(root->left);
    TravelsalNLR(root->right);   
}


};




int main()
{
    srand(time(NULL));
    TemplateBST A;
    string line = A.randomarray();
    TreeNode *head = A.stringToTreeNode(line);
    cout << "Print:\n";
    A.prettyPrintTree(head);
    cout << "Travelsal NLR:";A.TravelsalNLR(head);
//     int* p;
// while (*p!=123)
// {
//    cin >> *p;
//     cout << "delete"<<*p<<endl;
//     A.prettyPrintTree(head= A.deleteNode(head,*p)) ;
// }    
//    delete p;
    system("pause");
    return main();
}