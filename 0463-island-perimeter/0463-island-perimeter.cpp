class Solution {
public:
    //int peri;
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0){
            return 1;
        }

        if(grid[i][j] == -1) return 0;

        grid[i][j] = -1;

        // peri += dfs(grid, i-1,j);
        // peri += dfs(grid, i, j+1);
        // peri += dfs(grid, i+1, j);
        // peri += dfs(grid, i, j-1);
        return (dfs(grid, i-1,j)
                +dfs(grid, i, j+1)
                +dfs(grid, i+1, j)
                +dfs(grid, i, j-1));
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        // Solution 1 Iterative
        // int peri = 0;
        // int n = grid.size();
        // int m = grid[0].size();
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         if(grid[i][j]==1){
        //             if(i==0 || grid[i-1][j]==0) peri++; //top
        //             if(j==m-1 || grid[i][j+1]==0) peri++; //right
        //             if(i==n-1 || grid[i+1][j]==0) peri++; //bottom
        //             if(j==0 || grid[i][j-1]==0) peri++; //left
        //         }
        //     }
        // }
        // return peri;

        //Solution 2 DFS
        //peri = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    return dfs(grid,i,j);
                }
            }
        }
        return {};
    }
};