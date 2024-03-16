class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int>mp;
        int currlen = 0;
        int maxlen = 0;
        int sum = 0;
        mp[sum] = -1;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0) sum--;
            else sum++;
            if(mp.count(sum)){
                currlen = i - mp[sum];
                maxlen = max(maxlen, currlen);
            }
            else mp[sum] = i;
        }
        return maxlen;
    }
};