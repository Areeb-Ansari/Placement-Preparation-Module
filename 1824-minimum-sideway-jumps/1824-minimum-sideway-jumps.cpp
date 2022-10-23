class Solution {
private:
    int solveMem(vector<int>& obs, int currlane, int pos, vector<vector<int>>& dp){
        //base case
        int n = obs.size()-1;
        if(n == pos)
            return 0;
        
        if(dp[currlane][pos] != -1)
            return dp[currlane][pos];
        
        if(obs[pos+1] != currlane){
            return solveMem(obs, currlane, pos+1, dp);
        }
        else{
            int jump = INT_MAX;
            for(int i=1; i<=3; i++){
                if(obs[pos] != i && currlane != i)
                    jump = min(jump,1+solveMem(obs,i,pos, dp));
            }
            return dp[currlane][pos] = jump;
        }
    }
    
    int solveTab(vector<int>& obs){
        int n = obs.size()-1;
        vector<vector<int>> dp(4,vector<int>(obs.size(),INT_MAX));
        
        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;
        
        for(int pos = n-1; pos>=0; pos--){
            for(int lane=1; lane<=3; lane++){

                if(obs[pos+1] != lane){
                    dp[lane][pos] =  dp[lane][pos+1];
                }
                else{
                    int jump = INT_MAX;
                    for(int i=1; i<=3; i++){
                        if(obs[pos] != i && lane != i)
                            jump = min(jump,1+dp[i][pos+1]);
                    }
                    dp[lane][pos] = jump;
                }
                
            }
        }
        return min(dp[1][0]+1, min(dp[2][0], dp[3][0]+1));
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        //return solveRec(obstacles, 2, 0);
        
        // int s = obstacles.size();
        // vector<vector<int>> dp(4,vector<int>(s,-1));
        // return solveMem(obstacles, 2, 0, dp);
        
        return solveTab(obstacles);
    }
};