class Solution {
public:
int solveMem(vector<int>& prices, int fee, int day, int buy, vector<vector<int>>& dp){
        if(day == prices.size()) return 0;

        if(dp[day][buy] != -1) return dp[day][buy];

        int profit = 0;
        // buy-> 1 you buy
        // buy->0 you sell
        // HERE WE ONLY SUBTRACT FEE FROM EITHER BUY PHASE OR SELL PHASE COZ IT IS ONE CYCLE
        if(buy){
            //max of buy on that day or skip day
            profit = max((-prices[day]-fee + solveMem(prices, fee, day+1, 0, dp)),
                            (0 + solveMem(prices, fee, day+1, 1, dp)));
        }
        else{
            //max of sell on that day or skip day
            profit = max((prices[day] + solveMem(prices, fee, day+1, 1, dp)),
                            (0 + solveMem(prices, fee, day+1, 0, dp)));
        }
        return dp[day][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(), vector<int>(2,-1));
        return solveMem(prices, fee, 0, 1, dp);
    }
};