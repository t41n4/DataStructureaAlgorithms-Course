#include<lib.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;
        if(key>root->val) root->right = deleteNode(root->right,key);
        else if (key < root ->val) root->left =  deleteNode(root->left,key);
        else root = removeNode(root);  
        return root;
    }
   TreeNode* removeNode(TreeNode* root)
    {
       //nếu node cần xoá là node đơn
        if(root->left == NULL && root->right ==NULL) return NULL;
       //nếu node cần xoá là node với node->left = NULL
        else if(root->left == NULL) return root->right;
        //nếu node cần xoá là node với node->right = NULL
        else if(root->right == NULL) return root->left;
       // trường hợp còn lại (root->left != NULL && root->right != NULL)
        else 
        {
            TreeNode *temp;
            temp = root->right;
            //Tìm Node Bé nhất
            while(temp->left!=NULL)
            {
                temp = temp->left;
            }
             
            temp->left = root->left;
            return root->right;
        }
    }
};