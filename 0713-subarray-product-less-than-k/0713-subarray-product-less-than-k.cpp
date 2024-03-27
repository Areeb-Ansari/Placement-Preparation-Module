class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int n = nums.size();
        int l = 0;
        int r = 0;
        int subarrays = 0;
        int product = 1;

        while(r < n){
            product = product * nums[r];
            while(product >= k){
                product = product / nums[l];
                l++;
            }
            subarrays += r-l+1;
            r++;
        }
        return subarrays;
    }
};