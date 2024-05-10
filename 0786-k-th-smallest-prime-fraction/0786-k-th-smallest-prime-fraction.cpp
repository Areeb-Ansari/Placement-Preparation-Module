class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> pq;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                pq.push({arr[i]*1.0/arr[j], {arr[i], arr[j]}});
            }
        }

        for (int i=0; i<k-1; i++) {
            pq.pop();
        }
        return {pq.top().second.first, pq.top().second.second};

    }
};