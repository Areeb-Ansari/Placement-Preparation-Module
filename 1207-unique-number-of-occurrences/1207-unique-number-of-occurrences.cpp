class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int>mp;
        unordered_set<int>s;
        for(auto x : arr) mp[x]++;

        for(auto x : mp){
            if(s.count(x.second)) return false;
            s.insert(x.second);
        }
        return true;
    }
};