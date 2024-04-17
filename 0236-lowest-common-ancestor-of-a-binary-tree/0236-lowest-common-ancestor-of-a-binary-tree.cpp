/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node == NULL || node==p || node==q){
            return node;
        }

        TreeNode* left = dfs(node->left, p, q);
        TreeNode* right = dfs(node->right, p, q);

        if(left == NULL) return right;
        else if(right == NULL) return left;
        else return node;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};