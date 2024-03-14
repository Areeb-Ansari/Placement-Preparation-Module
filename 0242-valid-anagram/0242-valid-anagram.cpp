class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char,int>mp;
        for(auto ch : s){
            mp[ch]++;
        }
        for(auto th : t){
            if(mp[th] < 1) return false;
            mp[th]--;
        }
        return true;
    }
};