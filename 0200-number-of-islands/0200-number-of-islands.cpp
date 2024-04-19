class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]!='1'){
            return;
        }

        grid[i][j] = '0'; //marking visited we can only put 0 coz grid must have only 0 and 1

        dfs(grid, i-1, j); //top
        dfs(grid, i, j+1); //right
        dfs(grid, i+1, j); //bottom
        dfs(grid, i, j-1); //left
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};