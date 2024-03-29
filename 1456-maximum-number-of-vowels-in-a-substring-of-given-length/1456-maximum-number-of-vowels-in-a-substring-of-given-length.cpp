class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int l = 0;
        int r = k;
        int currcount = 0;
        for(int i=0; i<k; i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') currcount++;
        }

        int maxcount = currcount;
        while(r < n){
            if(k == maxcount) return k;
            if(s[r]=='a' || s[r]=='e' || s[r]=='i' || s[r]=='o' || s[r]=='u') currcount++;
            if(s[l]=='a' || s[l]=='e' || s[l]=='i' || s[l]=='o' || s[l]=='u') currcount--;
            maxcount = max(maxcount, currcount);
            l++;
            r++;
        }
        return maxcount;
    }
};