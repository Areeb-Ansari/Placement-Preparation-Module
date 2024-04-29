class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        int arxor = nums[0];
        for(int i=1; i<nums.size(); i++){
            arxor = arxor ^ nums[i];
        }

        while(k || arxor){
            bool arbit = arxor % 2;
            arxor = arxor/2;
            bool kbit = k % 2;
            k = k/2;
            if(kbit != arbit) ans++;
        }
        return ans;
    }
};