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
    bool dfs(TreeNode* root, int target, int curr){
        if(root == NULL) return false;

        curr += root->val;
        if(root->left == NULL && root->right == NULL){
            if(curr == target) return true;
            else return false;
        }

        return dfs(root->left, target, curr) || dfs(root->right, target, curr);
        //coz we want to return true if we get target at any point of time.
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum, 0);
    }
};