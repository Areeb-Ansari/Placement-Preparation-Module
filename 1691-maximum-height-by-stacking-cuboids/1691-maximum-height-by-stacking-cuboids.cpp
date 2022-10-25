class Solution {
private:
    bool check(vector<int> old, vector<int>newb){
        if(newb[0]<=old[0] && newb[1]<=old[1] && newb[2]<=old[2])
            return true;
        return false;
    }
    
    int solveSpace(vector<vector<int>>& nums){
        int n = nums.size();
        vector<int>currRow(n+1,0);
        vector<int>nextRow(n+1,0);
        
        for(int curr=n-1; curr>=0; curr--){
            for(int prev=curr-1; prev>=-1; prev--){
                
                int incl = 0;
                if(prev == -1 || check(nums[curr], nums[prev]))
                    incl = nums[curr][2] + nextRow[curr+1];
                int excl = nextRow[prev+1];

                currRow[prev+1] =  max(incl, excl);
            }
            nextRow = currRow;
        }
        return currRow[0];
    }
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &a : cuboids){
            sort(a.begin(), a.end());
        }
        
        sort(cuboids.begin(), cuboids.end());
        
        return solveSpace(cuboids);
    }
};