class Solution {
public:
    bool closeStrings(string word1, string word2) {

        if(word1.size() != word2.size()) return false;

        unordered_map<char, int>mp1,mp2;
        priority_queue<int>check1,check2;

        for(auto x : word1) mp1[x]++;
        for(auto x : word2) mp2[x]++;

        // if(mp1.size() != mp2.size()) return false;
        // return true;

        for(auto x : mp1){
            if(!mp2.count(x.first)) return false;
        }

        for(auto x : mp1){
            check1.push(x.second);
        }
        for(auto x : mp2){
            check2.push(x.second);
        }

        while(!check1.empty()){
            if(check1.top() != check2.top()) return false;
            check1.pop();
            check2.pop();
        }
        return true;
    }
};