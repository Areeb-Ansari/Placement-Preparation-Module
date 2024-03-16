class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int count = 1;
        for(int j=1; j<=chars.size(); j++){
            // while(j<chars.size() && chars[j] == chars[j-1]){
            //     j++;
            //     count++;
            // }
            if(j == chars.size() || chars[j] != chars[j-1]){
                chars[i] = chars[j-1];
                i++;
                if(count > 1) {
                    for(char ch : to_string(count)){
                        chars[i] = ch;
                        i++;
                    }
                }
                count = 0;
            }
            count++;
        }
        return i;
    }
};