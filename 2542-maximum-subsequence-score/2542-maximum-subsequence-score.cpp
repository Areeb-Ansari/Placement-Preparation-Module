class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b){
        return a.second > b.second;
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>>seq;

        for(int i=0; i<nums1.size(); i++){
            seq.push_back({nums1[i], nums2[i]});
        }

        sort(seq.begin(), seq.end(), cmp);

        priority_queue<int, vector<int>, greater<int>>pq;
        long long ans = 0;
        long long sum = 0;
        for(int i=0; i<seq.size(); i++){
            int n1 = seq[i].first;
            sum += n1;
            pq.push(n1);
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            if(pq.size() == k){
                int n2 = seq[i].second;
                ans = max(ans, sum * n2);
            }
        }
        return ans;
    }
};