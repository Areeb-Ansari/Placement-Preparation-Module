class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        unordered_set<int>s;
        for(auto x : nums){
            if(x>0) s.insert(x);
        }

        for(auto x : nums){
            if(x<0 && s.count(abs(x))){
                ans = max(ans, abs(x));
            }
        }
        return ans;
    }
};