class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k = 1;
        int l=0;
        int r;

        for(r=0; r<nums.size(); r++){
            if(nums[r] == 0) k--;
            if(k<0){
                if(nums[l]==0)k++;
                l++;
            }

        }
        return r-l-1;
    }
};