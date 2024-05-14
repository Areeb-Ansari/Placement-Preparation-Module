class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int a = INT_MAX, b = INT_MAX;

        for(int i=0; i<n; i++){
            if(nums[i] <= a){
                a = nums[i];
            }
            else if(nums[i] <= b){
                b = nums[i];
            }
            else return true;
        }
        return false;

        // int n = nums.size();
        // vector<int>pre(n);
        // vector<int>post(n);

        // pre[0] = nums[0];
        // for(int i=1; i<n; i++){
        //     pre[i] = min(nums[i], pre[i-1]);
        // }

        // post[n-1] = nums[n-1];
        // for(int i=n-2; i>=0; i--){
        //     post[i] = max(nums[i], post[i+1]);
        // }

        // for(int i=0; i<n; i++){
        //     if(pre[i] < nums[i] && nums[i] < post[i]){
        //         return true;
        //     }
        // }
        // return false;
    }
};