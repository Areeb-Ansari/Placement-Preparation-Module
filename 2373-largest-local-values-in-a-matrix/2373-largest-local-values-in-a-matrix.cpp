class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>local(n-2, vector<int>(n-2));

        for(int i=1; i<n-1; i++){
            for(int j=1; j<n-1; j++){
                int localMax = 0;

                for(int p=i-1; p<=i+1; p++){
                    for(int q=j-1; q<=j+1; q++){
                        localMax = max(localMax, grid[p][q]);
                    }
                }
                local[i-1][j-1] = localMax;
            }
        }
        return local;
    }
};