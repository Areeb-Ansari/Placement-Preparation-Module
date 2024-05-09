class Solution {
public:
    int solveRec(vector<int>& prices, int day, int buy){
        if(day == prices.size()) return 0;

        int profit = 0;
        // buy-> 1 you buy
        // buy->0 you sell
        if(buy){
            //max of buy on that day or skip day
            profit = max((-prices[day] + solveRec(prices, day+1, 0)),
                            (0 + solveRec(prices, day+1, 1)));
        }
        else{
            //max of sell on that day or skip day
            profit = max((prices[day] + solveRec(prices, day+1, 1)),
                            (0 + solveRec(prices, day+1, 0)));
        }
        return profit;
    }
    int solveMem(vector<int>& prices, int day, int buy, vector<vector<int>>& dp){
        if(day == prices.size()) return 0;

        if(dp[day][buy] != -1) return dp[day][buy];

        int profit = 0;
        // buy-> 1 you buy
        // buy->0 you sell
        if(buy){
            //max of buy on that day or skip day
            profit = max((-prices[day] + solveMem(prices, day+1, 0, dp)),
                            (0 + solveMem(prices, day+1, 1, dp)));
        }
        else{
            //max of sell on that day or skip day
            profit = max((prices[day] + solveMem(prices, day+1, 1, dp)),
                            (0 + solveMem(prices, day+1, 0, dp)));
        }
        return dp[day][buy] = profit;
    }
    int solveTab(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2,0));

        int profit;
        for(int day = n-1; day>=0; day--){
            for(int buy=0; buy<=1; buy++){
                if(buy){
                    profit = max((-prices[day] + dp[day+1][0]),
                                    (0 + dp[day+1][1]));
                }
                else{
                    profit = max((prices[day] + dp[day+1][1]),
                                    (0 + dp[day+1][0]));
                }
                dp[day][buy] = profit;
            }
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
        //return solveRec(prices, 0, 1);

        // vector<vector<int>>dp(prices.size(), vector<int>(2,-1));
        // return solveMem(prices, 0, 1, dp);

        return solveTab(prices);

    }
};