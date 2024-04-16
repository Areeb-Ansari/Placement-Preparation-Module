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
    void dfs(TreeNode* root, int val, int depth, int currdep){
        if(root == NULL) return;

        if(currdep < depth-1){
            dfs(root->left, val, depth, currdep+1);
            dfs(root->right, val, depth, currdep+1);
        }
        
        if(currdep == depth-1){ //depth-1 coz we want parent for modifying nodes
            TreeNode* prevleft = root->left;
            TreeNode* prevright = root->right;
            TreeNode* newleft = new TreeNode(val);
            TreeNode* newright = new TreeNode(val);

            root->left = newleft;
            root->right = newright;

            newleft->left = prevleft;
            newright->right = prevright;
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newnode = new TreeNode(val);
            newnode->left = root;
            return newnode;
        }

        dfs(root, val, depth, 1); // 1 is curr depth
        return root;
    }
};