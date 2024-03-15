class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int n = nums.size();
        // vector<int>ans(n,1);

        // //prefix product pass
        // for(int i=1; i<n; i++){
        //     ans[i] = ans[i-1]*nums[i-1];
        // }

        // //postfix product pass
        // int post = 1;
        // for(int i=n-2; i>=0; i--){
        //     post *= nums[i+1];
        //     ans[i] = ans[i] * post;
        // } 
        // return ans;
        //Attempt 2
        vector<int>ans(nums.size(),1);

        for(int i=1; i<nums.size(); i++){
            ans[i] = ans[i-1] * nums[i-1];
        }

        int post = 1;
        for(int i=nums.size()-2; i>=0; i--){
            post = post * nums[i+1];
            ans[i] = post * ans[i];
        }
        return ans;
    }
};