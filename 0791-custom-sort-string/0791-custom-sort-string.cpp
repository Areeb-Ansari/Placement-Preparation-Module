class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<int, int>mp;
        string ans;

        for(auto x : s) mp[x]++;

        for(auto x : order){
            if(mp[x]){
                while(mp[x]){
                    ans.push_back(x);
                    mp[x]--;
                }
                mp.erase(x);
            }
        }
        for(auto x : mp){
            for(int i=0; i<x.second; i++){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};