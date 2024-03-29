class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxele = INT_MIN;
        for(auto x : nums) maxele = max(maxele, x);

        int count = 0;
        int l = 0;
        long long ans = 0;
        for(int r=0; r<nums.size(); r++){
            if(nums[r] == maxele) count++;

            while((count > k) ||(l<=r && count == k && nums[l] != maxele)){
                if(nums[l] == maxele) count--;
                l++;
            }
            if(count == k) ans += l+1;
        }
        return ans;
    }
};