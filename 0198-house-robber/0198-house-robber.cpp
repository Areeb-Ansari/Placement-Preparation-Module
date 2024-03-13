class Solution {
private:
    int solveRec(vector<int>& arr, int n){
        //base case
        if(n==0)
        return arr[0];
        
        if(n<0)
        return 0;
        
        int incl = solveRec(arr,n-2) + arr[n];
        int excl = solveRec(arr,n-1) + 0;
        
        return max(incl,excl);
    }
    
    int solveMem(vector<int>& arr, int n, vector<int>& dp){
        //base case
        if(n==0)
        return arr[0];
        
        if(n<0)
        return 0;
        
        //step 3
        if(dp[n] != -1)
        return dp[n];
        
        int incl = solveMem(arr,n-2,dp) + arr[n];
        int excl = solveMem(arr,n-1,dp) + 0;
        
        dp[n] = max(incl,excl);
        return dp[n];
    }
    
    int solveTab(vector<int>& arr, int n){
        vector<int>dp(n,0);//step1
        
        //step2
        dp[0] = arr[0];
        
        
        //step 3
        for(int i=1; i<n; i++){
            int incl = dp[i-2] + arr[i];
            int excl = dp[i-1] + 0;
            dp[i] = max(incl,excl);
        }
        return dp[n-1];
    }
    
    int solveSpace(vector<int>& arr, int n){
        
        //step2
        int prev1 = arr[0];
        int prev2 = 0;
        
        //step 3
        for(int i=1; i<n; i++){
            int incl = prev2 + arr[i];
            int excl = prev1 + 0;
            int ans = max(incl,excl);
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        //recursion gives TLE
        //return solveRec(arr,n-1);
        
        // DP
        // vector<int>dp(n+1,-1); //step1
        // return solveMem(arr,n-1,dp);
        
        //Tabulation
        //return solveTab(arr,n);
        
        //Space optimization
        return solveSpace(nums,n);
    }
};