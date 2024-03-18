class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans = points.size();
        int prevend = points[0][1]; 

        for(int i=1; i<points.size(); i++){
            if(prevend >= points[i][0]){
                ans--;
                prevend = min(prevend, points[i][1]);
            }
            else prevend = points[i][1];
        }
        return ans;
    }
};