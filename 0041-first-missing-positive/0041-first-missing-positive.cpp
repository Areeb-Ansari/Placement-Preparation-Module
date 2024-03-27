class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //Solution-1 -- TC : O(n), SC : O(n)
        // priority_queue<int, vector<int>, greater<int>>pq;
        // for(auto x : nums){
        //     if(x>=0) pq.push(x);
        // }

        // if(pq.empty() && nums.size()) return 1;
        // if(pq.top()>=2) return 1;

        // int x = -1;
        // while(!pq.empty()){
        //     x = pq.top();
        //     pq.pop();
        //     if(x+1 != pq.top() && x != pq.top()) return x+1;
        // }
        // return x+1;

        //Solution-2 -- TC : O(n), SC : O(n)
        // int n = nums.size();
        // unordered_set<int>s;
        // for(auto x : nums){
        //     if(x>0) s.insert(x);
        // }
        // for(int i=1; i<=n+1; i++){
        //     if(!s.count(i)) return i;
        // }
        // return {};

        //Solution 3 -- TC:O(n), SC:O(1)
        int n = nums.size();

        //put 0 to -ve no
        for(int i=0; i<n; i++){
            if(nums[i]<0) nums[i] = 0;
        }

        for(int i=0; i<n; i++){
            int idx = abs(nums[i])-1;
            if(idx>=0 && idx<=n-1 && nums[idx]>0) nums[idx] = -nums[idx];
            if(idx>=0 && idx<=n-1 && nums[idx]==0) nums[idx] = -(n+1);
        }

        for(int i=1; i<=n; i++){
            if(nums[i-1] >= 0) return i;
        }
        return n+1;

    }
};