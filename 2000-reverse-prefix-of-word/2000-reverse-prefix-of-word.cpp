class Solution {
public:
    string reversePrefix(string word, char ch) {
        int l = 0;
        int r = -1;
        for(int i=0; i<word.size(); i++){
            if(ch == word[i]){
                r = i;
                break;
            }
        }

        if(r == -1) return word;

        while(l<r){
            swap(word[l], word[r]);
            r--;
            l++;
        }
        return word;
    }
};