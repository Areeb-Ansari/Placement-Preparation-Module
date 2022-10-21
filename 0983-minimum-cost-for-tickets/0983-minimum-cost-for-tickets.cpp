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
    
    int solveTab(int n, vector<int>& days, vector<int>& costs){
        vector<int>dp(n+1,INT_MAX);
        
        dp[n] = 0;
        
        for(int k=n-1; k>=0; k--){
            // 1 day pass
            int op1 = costs[0] + dp[k+1];

            // 7 day pass
            int i = k;
            while(i<n && days[i] < days[k]+7){
                i++;
            }
            int op2 =costs[1] + dp[i];

            //30 days pass
            i = k;
            while(i<n && days[i] < days[k]+30){
                i++;
            }
            int op3 =costs[2] + dp[i];
            
            dp[k] = min(op1,min(op2,op3));
        }
        return dp[0];
    }
    
    int space(vector<int>& days, vector<int>& cost){
        int ans = 0;
        
        queue<pair<int,int>> month; // <days,cost till day>
        queue<pair<int,int>> week;
        
        for(int day : days){
            //step 1 - remove expire days
            while(!month.empty() && month.front().first+30 <= day)
                month.pop();
            while(!week.empty() && week.front().first+7 <= day)
                week.pop();
            
            //step 2- push current days cost
            month.push(make_pair(day,ans+cost[2]));
            week.push(make_pair(day,ans+cost[1]));
            
            // step 3 - update ans
            ans = min(ans+cost[0], min(week.front().second,month.front().second));
        }
        return ans;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        //return solveRec(n,days,costs,0);
        
        // vector<int> dp(n+1,-1);
        // return solveMem(n,days,costs,0,dp);
        
        //return solveTab(n,days,costs);
        
        return space(days,costs);
    }
};