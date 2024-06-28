class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0;
        long long val = 1;
        vector<int>degree(n);
        for(auto road : roads){
            int u = road[0];
            int v = road[1];

            degree[u]++;
            degree[v]++;
        }

        sort(degree.begin(), degree.end());
        for(auto d : degree){
            ans += d * val;
            val++;
        }
        return ans;
    }
};