class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin(), intervals.end());
        int prevright = intervals[0][1];

        for(int i=1; i<intervals.size(); i++){
            if(prevright > intervals[i][0]){
                ans++;
                prevright = min(prevright, intervals[i][1]);
            }
            else prevright = intervals[i][1];
        }
        return ans;


    }
};