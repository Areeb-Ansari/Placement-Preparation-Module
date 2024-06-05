class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>ans;
        unordered_map<char, int>prev;
        for(char c : words[0]) prev[c]++;

        for(int i=1; i<words.size(); i++){
            unordered_map<char, int>curr;
            for(char c : words[i]) curr[c]++;

            for(auto w : words[0]){
                prev[w] = min(prev[w], curr[w]);
            }
        }

        for(auto x : prev){
            while(x.second--){
                ans.push_back(string(1,x.first));
            }
        }
        return ans;
    }
};