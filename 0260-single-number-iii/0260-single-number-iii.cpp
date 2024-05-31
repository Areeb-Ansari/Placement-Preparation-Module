class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        // TC : O(n)   SC:O(n)
        // vector<int>ans;
        // unordered_map<int, int>mp;

        // for(auto n : nums) mp[n]++;

        // for(auto x : mp){
        //     if(x.second == 1) ans.push_back(x.first);
        // }
        // return ans;

        int xor2no = 0;
        for (int num : nums) {
            xor2no ^= num;
        }
        unsigned int lowestBit = xor2no & -(unsigned int)xor2no;

        vector<int> result(2, 0);
        for (int num : nums) {
            if ((lowestBit & num) == 0) {
                result[0] ^= num;
            } else {
                result[1] ^= num;
            }
        }

        return result;
    }
};