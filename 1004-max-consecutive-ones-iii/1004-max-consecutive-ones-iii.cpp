class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r;
        for(r=0; r<nums.size(); r++){
            if(nums[r] == 0) k--;
            if(k<0){
                if(nums[l] == 0)k++;
                l++;
            }
        }
        return r-l;


        // int l=0;
        // int r;
        // int ans = 0;
        // for(r=0; r<nums.size(); r++){
        //     if(nums[r] == 0) k--;
        //     if(k<0){
        //         if(nums[l] == 0)k++;
        //         l++;
        //     }
        //     ans = max(ans, r-l+1);
        // }
        // return ans;
    }
};