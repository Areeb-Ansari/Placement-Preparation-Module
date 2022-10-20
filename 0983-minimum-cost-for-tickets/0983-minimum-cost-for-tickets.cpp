class Solution {
private:
    int solveRec(int n, vector<int>& days, vector<int>& costs, int index){
        //base case
        if(index >= n)
            return 0;
        
        // 1 day pass
        int op1 = costs[0] + solveRec(n,days,costs,index+1);
        
        // 7 day pass
        int i = index;
        while(i<n && days[i] < days[index]+7){
            i++;
        }
        int op2 =costs[1] + solveRec(n,days,costs,i);
        
        //30 days pass
        i = index;
        while(i<n && days[i] < days[index]+30){
            i++;
        }
        int op3 =costs[2] + solveRec(n,days,costs,i);
        
        return min(op1,min(op2,op3));
    }
    
    int solveMem(int n, vector<int>& days, vector<int>& costs, int index, vector<int>&      dp){
        //base case
        if(index >= n)
            return 0;
        
        if(dp[index] != -1)
            return dp[index];
        
        // 1 day pass
        int op1 = costs[0] + solveMem(n,days,costs,index+1,dp);
        
        // 7 day pass
        int i = index;
        while(i<n && days[i] < days[index]+7){
            i++;
        }
        int op2 =costs[1] + solveMem(n,days,costs,i,dp);
        
        //30 days pass
        i = index;
        while(i<n && days[i] < days[index]+30){
            i++;
        }
        int op3 =costs[2] + solveMem(n,days,costs,i,dp);
        
         return dp[index] =  min(op1,min(op2,op3));
    }
    
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        //return solveRec(n,days,costs,0);
        
        vector<int> dp(n+1,-1);
        return solveMem(n,days,costs,0,dp);
    }
};