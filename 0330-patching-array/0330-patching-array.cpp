class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long int patch = 0, maxSum = 0, i = 0;

        while(maxSum < n){
            if(i < nums.size() && maxSum+1 >= nums[i]){
                maxSum += nums[i];
                i++;
            }
            else{
                patch++;
                maxSum += (maxSum+1);
            }
        }
        return patch;
    }
};