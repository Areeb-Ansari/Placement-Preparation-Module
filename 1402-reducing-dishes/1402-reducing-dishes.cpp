class Solution {
private:
    int solveRec(vector<int>& sat,int index, int time){
        //base case
        int n = sat.size();
        if(index == n)
            return 0;
        
        int incl = sat[index]*(time+1) + solveRec(sat,index+1,time+1);
        int excl = 0 + solveRec(sat,index+1,time);
        
        return max(incl, excl);
    }
    
    int solveMem(vector<int>& sat,int index, int time, vector<vector<int>>& dp){
        //base case
        int n = sat.size();
        if(index == n)
            return 0;
        
        if(dp[index][time] != -1)
            return dp[index][time];
        
        int incl = sat[index]*(time+1) + solveMem(sat,index+1,time+1,dp);
        int excl = 0 + solveMem(sat,index+1,time,dp);
        
        return dp[index][time] =  max(incl, excl);
    }
    
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        // return solveRec(satisfaction, 0, 0);
        
        int n = satisfaction.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return solveMem(satisfaction, 0, 0, dp);
    }
};