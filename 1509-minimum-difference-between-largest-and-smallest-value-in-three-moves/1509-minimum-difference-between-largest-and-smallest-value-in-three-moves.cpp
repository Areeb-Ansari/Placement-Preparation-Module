class Solution {
public:
    int minDifference(vector<int>& nums) {
        // SOlution 1
        // int n = nums.size();
        // if(n<=4) return 0;
        // sort(nums.begin(), nums.end());

        // return min({nums[n-1] - nums[3],
        //             nums[n-4] - nums[0],
        //             nums[n-3] - nums[1],
        //             nums[n-2] - nums[2]});

        // solution 2
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(auto x : nums){
            maxHeap.push(x);
            minHeap.push(x);

            if(maxHeap.size() > 4) maxHeap.pop();
            if(minHeap.size() > 4) minHeap.pop();
        }

        vector<int>minmax(8);
        for(int i=3; i>=0; i--){
            minmax[i] = maxHeap.top();
            maxHeap.pop(); 
        }

        for(int i=4; i<8; i++){
            minmax[i] = minHeap.top();
            minHeap.pop();
        }

        int n = minmax.size();

        return min({minmax[n-1] - minmax[3],
                    minmax[n-4] - minmax[0],
                    minmax[n-3] - minmax[1],
                    minmax[n-2] - minmax[2]});
    }
};