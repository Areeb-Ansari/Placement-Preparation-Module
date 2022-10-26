#define MOD 1000000007
class Solution {
private:
    int solveRec(int dice, int face, int target){
        //base case
        if(target<0) return 0;
        if(target==0 && dice!= 0) return 0;
        if(target!=0 && dice==0) return 0;
        if(target==0 && dice==0) return 1;
        
        int ans = 0;
        for(int i=1; i<=face; i++){
            ans = (ans%MOD + (solveRec(dice-1, face, target-i))%MOD)%MOD;
        }
        return ans;
    }
    int solveMem(int dice, int face, int target, vector<vector<int>>& dp){
        //base case
        if(target<0) return 0;
        if(target==0 && dice!= 0) return 0;
        if(target!=0 && dice==0) return 0;
        if(target==0 && dice==0) return 1;
        
        if(dp[dice][target] != -1)
            return dp[dice][target];
        
        int ans = 0;
        for(int i=1; i<=face; i++){
            ans = (ans%MOD + (solveMem(dice-1, face, target-i, dp))%MOD)%MOD;
        }
        return dp[dice][target] = ans;
    }
    
    int solveTab(int dice, int face, int target){
        vector<vector<int>>dp(dice+1, vector<int>(target+1, 0));
        
        //by base case analysis of top down
        dp[0][0] = 1;
        
        for(int d=1; d<=dice; d++){
            for(int t=1; t<=target; t++){
                
                int ans = 0;
                for(int i=1; i<=face; i++){
                    if(t-i>=0)
                    ans = (ans%MOD + (dp[d-1][t-i])%MOD)%MOD;
                }
                dp[d][t] = ans;
                
            }
        }
        return dp[dice][target];
    }
    
    int solveSpace(int dice, int face, int target){
        vector<int>prev(target+1, 0);
        vector<int>curr(target+1, 0);
        
        //by base case analysis of top down
        prev[0] = 1;
        
        for(int d=1; d<=dice; d++){
            for(int t=1; t<=target; t++){
                
                int ans = 0;
                for(int i=1; i<=face; i++){
                    if(t-i>=0)
                    ans = (ans%MOD + (prev[t-i])%MOD)%MOD;
                }
                curr[t] = ans;
                
            }
            prev = curr;
        }
        return curr[target];
    }
    
public:
    int numRollsToTarget(int n, int k, int target) {
        //return solveRec(n, k, target);
        
        // vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        // return solveMem(n, k, target, dp);
        
        //return solveTab(n, k, target);
        
        return solveSpace(n, k, target);
    }
};