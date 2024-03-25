class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // solution 2 : TC O(n), SC O(n)
        // unordered_set<int>s;
        // vector<int>ans;
        // for(int i=0; i<nums.size(); i++){
        //     if(s.count(nums[i])){
        //         ans.push_back(nums[i]);
        //     }
        //     else s.insert(nums[i]);
        // }
        // return ans;

        //Solution 3
        vector<int>ans;
        for(int i=0; i<nums.size(); i++){
            int idx = abs(nums[i])-1;
            if(nums[idx] < 0) ans.push_back(abs(nums[i]));
            else nums[idx] = -nums[idx];
        }
        return ans;
    }
};