class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // solution 1
        // int ans = numBottles;

        // while(numBottles >= numExchange){
        //     int rem = numBottles % numExchange;
        //     int full = numBottles / numExchange;
        //     ans += full;
        //     numBottles = full + rem;
        // }
        // return ans;

        //solution 2
        return numBottles + (numBottles-1) / (numExchange-1);
    }
};