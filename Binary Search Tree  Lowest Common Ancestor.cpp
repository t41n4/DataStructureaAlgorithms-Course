
#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

void print()
    {
        for (int ix = 0; ix < _level; ++ix) cout << ' ';
        cout << _val << endl;
        ++_level;
        if (_lchild)
        {
            _lchild->print();
            --_level;
        }
        if (_rchild)
        {
            _rchild->print();
            --_level;
        }
    }
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
  
    Node *lca(Node *root, int v1,int v2) {
    while(root!=NULL) 
        {
            if(root->data >= v1 && root->data>v2) return lca(root->left,v1,v2);
            else if(root->data <=v2&&root->data<v1) return lca(root->right,v1,v2);
            else return root;
        }
     return NULL;
    }
}; //End of Solution
int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  	
  	int v1, v2;
  	std::cin >> v1 >> v2;
  
    Node *ans = myTree.lca(root, v1, v2);
    
  	std::cout << ans->data;
	system("pause");
    return 0;
}
