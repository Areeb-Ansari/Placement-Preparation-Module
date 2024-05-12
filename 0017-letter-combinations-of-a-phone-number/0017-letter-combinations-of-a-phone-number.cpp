class Solution {
public:
    void solve(int i, string& digits, string& curr, vector<string>& ans, unordered_map<char, string>& mp){
        if(curr.size() == digits.size()){
            ans.push_back(curr);
        }

        string temp = mp[digits[i]];
        for(int j=0; j<temp.size(); j++){
            curr.push_back(temp[j]);
            solve(i+1, digits, curr, ans, mp);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size()==0) return ans;
        string curr;
        unordered_map<char, string>mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        solve(0, digits, curr, ans, mp);
        return ans;
    }
};