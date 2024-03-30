class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int ans = 0;
        int lnear = 0;
        int lfar = 0;

        for(int r=0; r<nums.size(); r++){
            mp[nums[r]]++;

            while(mp.size() > k){
                mp[nums[lnear]]--;
                if(mp[nums[lnear]] == 0) mp.erase(nums[lnear]);
                lnear++;
                lfar = lnear;
            }

            while(mp[nums[lnear]] > 1){
                mp[nums[lnear]]--;
                lnear++;
            }

            if(mp.size() == k) ans += lnear - lfar + 1;
        }
        return ans;
    }
};