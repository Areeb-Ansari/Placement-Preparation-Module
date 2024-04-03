class Solution {
public:
    void flood(int i, int j, vector<vector<int>>& image, int color, int oldcolor, int n, int m){
        if(i<0 || j<0 || i==m || i==n || oldcolor != image[i][j]) return;

        image[i][j] = color;

        flood(i+1,j,image,color,oldcolor,n,m);
        flood(i-1,j,image,color,oldcolor,n,m);
        flood(i,j+1,image,color,oldcolor,n,m);
        flood(i,j-1,image,color,oldcolor,n,m);
        return;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int oldcolor = image[sr][sc];

        if(oldcolor == color) return image;

        flood(sr,sc,image,color,oldcolor,n,m);

        return image;
    }
};