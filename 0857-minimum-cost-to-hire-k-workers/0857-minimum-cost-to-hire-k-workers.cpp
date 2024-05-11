class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double, int>>ratio;
        priority_queue<int>pq;

        for(int i=0; i<wage.size(); i++){
            ratio.push_back({wage[i]*1.0/quality[i], quality[i]});
        }
        sort(begin(ratio), end(ratio));

        int total_quality = 0;
        double ans = DBL_MAX;
        for(int i=0; i<ratio.size(); i++){
            pq.push(ratio[i].second);
            total_quality += ratio[i].second;

            if(pq.size() > k){
                total_quality -= pq.top();
                pq.pop();
            }
            if(pq.size() == k){
                ans = min(ans, total_quality * ratio[i].first);
            }
        }
        return ans;
    }
};