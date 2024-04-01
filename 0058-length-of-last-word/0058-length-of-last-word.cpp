class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1;
        int ans = 0;

        while(s[i] == ' '){
            i--;
        }
        for(; i>=0; i--){
           
            if(s[i] == ' ') return ans;
            ans++;
        }
        return ans;
    }
};