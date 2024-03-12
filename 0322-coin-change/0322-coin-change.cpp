class Solution {
private:
    int solveRec(vector<int>& coins, int x){
        //base case
        if(x==0)
            return 0;
        if(x<0)
            return INT_MAX;
        
        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            int ans = solveRec(coins, x-coins[i]);
            if(ans != INT_MAX)//if ans is valid;target is >0
                mini = min(mini, 1+ans); // +1 to consider curr coin
        }
        return mini;
    }
    
    int solveMem(vector<int>& coins, int x, vector<int>& dp){
        //base case
        if(x==0)
            return 0;
        if(x<0)
            return INT_MAX;
        
        //step 3
        if(dp[x] != -1)
            return dp[x];
        
        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            int ans = solveMem(coins, x-coins[i], dp);
            if(ans != INT_MAX)//if ans is valid;target is >0
                mini = min(mini, 1+ans); // +1 to consider curr coin
        }
        dp[x] = mini; // step 2
        return dp[x];
    }

    int solveTab(vector<int>& coins, int x){
        int n = coins.size();
        vector<int>dp(x+1, INT_MAX);

        dp[0] = 0;

        for(int i=1; i<=x; i++){
            for(int j=0; j<n; j++){
                if(i-coins[j]>=0 && dp[i-coins[j]] != INT_MAX)
                dp[i] = min(dp[i], 1+dp[i-coins[j]]);
            }
        }
        if(dp[x] == INT_MAX) return -1;
        return dp[x];
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        // int ans = solveRec(coins, amount);
        // if(ans != INT_MAX)
        //     return ans;
        // return -1;
        
        // vector<int>dp(amount+1, -1); // step 1 to create dp array
        // int ans = solveMem(coins, amount, dp);
        // if(ans != INT_MAX)
        //      return ans;
        //  return -1;
        return solveTab(coins, amount);
    }
};