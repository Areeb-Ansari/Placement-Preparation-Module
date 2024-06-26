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
        if(root == NULL) return root;

        if(key < root->val) root->left = deleteNode(root->left, key);
        else if(key > root->val) root->right = deleteNode(root->right, key);
        else{
            if(root->left == NULL) return root->right; // both if statements combined handles
            if(root->right == NULL) return root->left; // Case 1 and 2

            TreeNode* curr = root->right;
            while(curr->left) curr = curr->left;
            root->val = curr->val;
            root->right = deleteNode(root->right, root->val);
        }
        return root;
    }
};