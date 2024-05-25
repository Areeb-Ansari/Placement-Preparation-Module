class Solution {
public:
    string join(vector<string>& words){
        string sent;
        for(int i=0; i<words.size(); i++){
            if(i>0) sent += " ";
            sent += words[i];
        }
        return sent;
    }
    void solve(int i, string& s, unordered_set<string>& exist, vector<string>& cur, vector<string>& ans){
        if(i == s.size()){
            ans.push_back(join(cur));
            return;
        }

        for(int j=i; j<s.size(); j++){
            string word = s.substr(i, j-i+1);
            if(exist.find(word) != exist.end()){
                cur.push_back(word);
                solve(j+1, s, exist, cur, ans);
                cur.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> exist(wordDict.begin(), wordDict.end());
        vector<string> ans;
        vector<string> cur;

        solve(0, s, exist, cur, ans);
        return ans;
    }
};