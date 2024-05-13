class Solution {
public:
    void help(int i, int k, int n, int currsum, vector<int>& subset, vector<vector<int>>& ans){
        if(k<0) return;
        if(currsum==n){
            if(k==0){
                ans.push_back(subset);
            }
            return;
        }
        if(i==10) return;


        // take 
        currsum += i;
        subset.push_back(i);
        help(i+1, k-1, n, currsum, subset, ans);
        currsum -= i;
        subset.pop_back();

        //not take
        help(i+1, k, n, currsum, subset, ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int>subset;
        help(1, k, n, 0, subset, ans);
        return ans;
        
    }
};