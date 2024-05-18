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
    int ans = 0;
    int dfs(TreeNode* root){
        if(root == NULL) return 0;

        int l_extra = dfs(root->left);
        int r_extra = dfs(root->right);
        int extra = root->val - 1 + l_extra + r_extra;
        ans += abs(extra);
        return extra;
    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return ans;
    }
};