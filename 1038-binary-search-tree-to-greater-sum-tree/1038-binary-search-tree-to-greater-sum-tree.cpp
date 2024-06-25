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
    // int totalsum(TreeNode* root, int sum){
    //     if(root==NULL) return 0;
    //     if(root->left == NULL && root->right == NULL) return root->val;

    //     sum += totalsum(root->left, sum) + totalsum(root->right, sum);

    //     return sum;
        
    // }
    int sum = 0;
    void dfs(TreeNode* root){
        // reverse inorder RRL
        if(root == NULL) return;

        dfs(root->right);
        sum += root->val;
        root->val = sum;
        dfs(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        // int sum = 0;
        // sum = totalsum(root, sum);
        // root->val=sum;
        // return root;

        dfs(root);
        return root;
    }
};