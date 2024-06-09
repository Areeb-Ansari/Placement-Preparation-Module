class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int>freq; //rem,count of rem till now
        freq[0] = 1; //intially 0 as rem with 1 freq count
        int ans = 0;
        int sum = 0;
        int rem = 0;

        for(auto n : nums){
            sum += n;
            rem = sum % k;
            if(rem < 0) rem += k;

            if(freq.count(rem)){
                ans += freq[rem];
            }
            freq[rem]++;
        }
        return ans;
    }
};