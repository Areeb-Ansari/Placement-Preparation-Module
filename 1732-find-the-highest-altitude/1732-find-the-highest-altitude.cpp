class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int>pre(n+1);
        int high = 0;
        for(int i=1; i<=n; i++){
            pre[i] = pre[i-1] + gain[i-1];
            high = max(high, pre[i]);
        }
        return high;
    }
};