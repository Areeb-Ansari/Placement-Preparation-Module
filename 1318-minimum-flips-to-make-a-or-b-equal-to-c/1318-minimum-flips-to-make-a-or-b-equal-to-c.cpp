class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flip=0;
        while(a || b || c){
            bool abit = a%2; a/=2;
            bool bbit = b%2; b/=2;
            bool cbit = c%2; c/=2;

            if((abit==1 && bbit==1) && !cbit) flip = flip+2;
            else if((abit | bbit) != cbit) flip++;
        }
        return flip;
    }
};