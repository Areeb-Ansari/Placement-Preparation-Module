class Solution {
public:
    bool checkValidString(string s) {
        int leftmin=0,leftmax=0;
        for(auto str : s){
            if(str == '('){
                leftmin++;
                leftmax++;
            }
            else if(str == ')'){
                leftmin--;
                leftmax--;
            }
            else{
                leftmin--;
                leftmax++;
            }
            if(leftmax<0) return false;
            if(leftmin<0) leftmin = 0;
        }
        return !leftmin;
    }
};