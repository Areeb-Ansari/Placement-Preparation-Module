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
    long long int count;
    unordered_map<long long int, long long int>mp; // <presum,no. of waysto generate presum>

    void dfs(TreeNode* root, long long int curr, long long int target){ //curr -> curr sum 
        if(root == NULL) return;
        curr += root->val;

        if(mp.count(curr - target)){
            count += mp[curr - target];
        }
        if(!mp.count(curr)) mp[curr] = 1;
        else mp[curr]++;
        dfs(root->left, curr, target);
        dfs(root->right, curr, target);
        mp[curr]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        count = 0;
        mp[0] = 1;
        dfs(root, 0, targetSum);
        return count;
    }
};