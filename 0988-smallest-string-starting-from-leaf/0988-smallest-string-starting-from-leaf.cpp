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
    string small;
    void dfs(TreeNode* root, string& curr){
        if(root == NULL) return;

        curr = char('a'+root->val) + curr;

        if(root->left==NULL && root->right==NULL){
            if(small.empty() || curr<small){
                small = curr;
            }
        }

        dfs(root->left, curr);
        dfs(root->right, curr);
        
        curr.erase(0,1);
    }
    string smallestFromLeaf(TreeNode* root) {
        string curr = "";
        dfs(root, curr);
        return small;
    }
};