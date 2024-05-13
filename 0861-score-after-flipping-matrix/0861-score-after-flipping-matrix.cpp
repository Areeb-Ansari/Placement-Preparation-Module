class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m=grid[0].size();
        int ans = n * (1 << (m-1));

        for(int j=1; j<m; j++){
            int colcount = 0;
            for(int i=0; i<n; i++){
                colcount += grid[i][0]==0 ? (grid[i][j]^1) : grid[i][j];
            }

            if(colcount < n-colcount){
                ans += (n-colcount) * (1 << (m-1-j));
            }
            else{
                ans += colcount * (1 << (m-1-j));
            }
        }
        return ans;



        // sol1
        // int ans = 0;
        // int n = grid.size(), m=grid[0].size();

        // //row flip
        // for(int i=0; i<n; i++){
        //     if(grid[i][0] == 0){
        //         for(int j=0; j<m; j++){
        //             grid[i][j] ^= 1; 
        //         }
        //     }
        // }

        // // col flip
        // for(int j=1; j<m; j++){
        //     int onecount = 0;
        //     for(int i=0; i<n; i++){
        //         onecount += grid[i][j];
        //     }
        //     if(onecount < n-onecount){
        //         for(int i=0; i<n; i++){
        //             grid[i][j] ^= 1;
        //         }
        //     }
        // }

        // //at last cal the ans
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         ans += grid[i][j] << (m-1-j);
        //     }
        // }
        // return ans;
    }
};