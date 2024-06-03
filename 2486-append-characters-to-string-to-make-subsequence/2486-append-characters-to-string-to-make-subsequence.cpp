class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.size();
        int m = t.size();
        int i = 0, j = 0;
        for(int i=0; i<n; i++){
            if(s[i] == t[j]) j++;
            if(j == m) return 0;
        }
        return m-j;
    }
};