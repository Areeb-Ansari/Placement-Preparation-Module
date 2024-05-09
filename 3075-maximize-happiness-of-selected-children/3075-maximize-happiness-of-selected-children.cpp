class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        priority_queue<int>pq;
        for(auto h : happiness) pq.push(h);

        for(int i=0; i<k; i++){
            int happy = pq.top();
            pq.pop();
            if(happy - i <=0) return ans;
            ans = ans + happy-i;
        }
        return ans;

        // sorting
        // long long ans = 0;
        // sort(happiness.begin(), happiness.end(), greater<int>());

        // for(int i=0; i<k; i++){
        //     if(happiness[i] - i <=0) return ans;
        //     ans = ans + happiness[i]-i;
        // }
        // return ans;
    }
};