class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Solutiuon 1- sorting
        // sort(nums.begin(), nums.end());
        // for(int i=0; i<nums.size()-1; i++){
        //     if(nums[i]==nums[i+1]) return true;
        // }
        // return false;

        //Solution 2 - set
        unordered_set<int>s;
        for(int i=0; i<nums.size(); i++){
            if(s.count(nums[i]) > 0) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};