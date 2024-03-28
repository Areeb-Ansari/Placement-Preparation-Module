class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxavg = 0;
        for(int i=0; i<k; i++){
            maxavg += nums[i];
        }
        maxavg /= k;
        double prev = maxavg;
        int l = 0;
        int r = k-1;

        while(r < nums.size()-1){
            r++;
            double curr = prev - (double)nums[l]/k + (double)nums[r]/k;
            l++;
            prev = curr;
            maxavg = max(maxavg, curr);
        }
        return maxavg;
    }
};