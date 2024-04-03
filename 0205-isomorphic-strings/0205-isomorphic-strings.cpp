class Solution {
public:
    bool isIsomorphic(string s, string t) {

        unordered_map<char, char>mpst,mpts;

        for(int i=0; i<s.size(); i++){
            if(mpst.count(s[i]) && mpst[s[i]] != t[i] || mpts.count(t[i]) && mpts[t[i]] != s[i]) return false;

            mpst[s[i]] = t[i];
            mpts[t[i]] = s[i];
        }
        return true;
    }
};