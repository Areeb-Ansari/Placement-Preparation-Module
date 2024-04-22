class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>vis(deadends.begin(), deadends.end());
        queue<pair<string, int>>q; //lock,moves
        if(vis.count("0000")) return -1;

        q.push({"0000", 0});
        vis.insert("0000");

        while(!q.empty()){
            string curr = q.front().first;
            int move = q.front().second;
            q.pop();

            if(curr == target) return move;

            for(int i=0; i<4; i++){
                for(int dig : {-1, 1}){
                    int newdig = (curr[i] - '0' + dig + 10)%10;
                    string newcomb = curr;
                    newcomb[i] = '0' + newdig;

                    if(!vis.count(newcomb)){
                        vis.insert(newcomb);
                        q.push({newcomb, move+1});
                    }
                }
            }
        }
        return -1;
    }
};