class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>prefmax(n);
        vector<int>sufmax(n);

        int pmax = 0;
        for(int i=0; i<n; i++){
            if(pmax < height[i]) pmax = height[i];
            prefmax[i] = pmax;
        }

        int smax = 0;
        for(int i=n-1; i>=0; i--){
            if(smax < height[i]) smax = height[i];
            sufmax[i] = smax;
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            ans += min(prefmax[i], sufmax[i]) - height[i]; 
        }
        return ans;
    }
};