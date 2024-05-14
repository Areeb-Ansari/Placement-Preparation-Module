class Solution {
public:
    vector<int>dx = {-1,0,0,1};
    vector<int>dy = {0,-1,1,0};

    int dfs(int i, int j, vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0){
            return 0;
        }

        int maxSum=0;
        int currGold = grid[i][j];
        for(int d=0; d<4; d++){
            int ni = i + dx[d];
            int nj = j + dy[d];
            grid[i][j] = 0;
            maxSum = max(maxSum, currGold + dfs(ni, nj, grid));
            grid[i][j] = currGold;
        }
        return maxSum;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] != 0) 
                    ans = max(ans, dfs(i,j,grid));
            }
        }
        return ans;


    }
};