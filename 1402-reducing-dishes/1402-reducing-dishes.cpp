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
    
    int solveTab(vector<int>& sat){
        int n = sat.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        
        //for base case analysis when index = n mark it as 0
        //which has already been done while intialization of dp array
        //since last index = n
        //so loop back from index = n-1
        
        for(int index=n-1; index>=0; index--){
            for(int time=index; time>=0; time--){
                
                int incl = sat[index]*(time+1) + dp[index+1][time+1];
                int excl = 0 + dp[index+1][time];

                dp[index][time] =  max(incl, excl);
            }
        }
        return dp[0][0];
    }
    
    int solveSpace(vector<int>& sat){
        int n = sat.size();
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);
        
        for(int index=n-1; index>=0; index--){
            for(int time=index; time>=0; time--){
                
                int incl = sat[index]*(time+1) + next[time+1];
                int excl = 0 + next[time];

                curr[time] =  max(incl, excl);
            }
            next = curr;
        }
        return curr[0];
    }
    
    int solveSpace2(vector<int>& sat){
        int n = sat.size();
        vector<int>curr(n+1,0);
        
        for(int index=n-1; index>=0; index--){
            for(int time=0; time<=index; time++){
                
                int incl = sat[index]*(time+1) + curr[time+1];
                int excl = 0 + curr[time];

                curr[time] =  max(incl, excl);
            }
        }
        return curr[0];
    }
    
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        // return solveRec(satisfaction, 0, 0);
        
        int n = satisfaction.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        // return solveMem(satisfaction, 0, 0, dp);
        
        //return solveTab(satisfaction);
        
        //return solveSpace(satisfaction);
        
        return solveSpace2(satisfaction);
    }
};