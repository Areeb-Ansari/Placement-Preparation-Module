class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // solution1 ___ 2 is also the same but a diff way
        // if(word1.size() != word2.size()) return false;

        // unordered_map<char, int>mp1,mp2;
        // priority_queue<int>check1,check2;

        // for(auto x : word1) mp1[x]++;
        // for(auto x : word2) mp2[x]++;

        // for(auto x : mp1){
        //     if(!mp2.count(x.first)) return false;
        // }

        // for(auto x : mp1){
        //     check1.push(x.second);
        // }
        // for(auto x : mp2){
        //     check2.push(x.second);
        // }

        // while(!check1.empty()){
        //     if(check1.top() != check2.top()) return false;
        //     check1.pop();
        //     check2.pop();
        // }
        // return true;

        vector<int>freq1(26),freq2(26);
        vector<int>vis1(26,false),vis2(26,false);

        for(auto c : word1){
            freq1[c-'a']++;
            vis1[c-'a'] = true;
        } 
        for(auto c : word2){
            freq2[c-'a']++;
            vis2[c-'a'] = true;
        } 

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2 && vis1 == vis2;


    }
};