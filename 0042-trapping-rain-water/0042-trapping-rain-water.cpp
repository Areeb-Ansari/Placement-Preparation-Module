class Solution {
public:
    int trap(vector<int>& height) {
         int n = height.size();
//         vector<int>prefmax(n);
//         vector<int>sufmax(n);

//         int pmax = 0;
//         for(int i=0; i<n; i++){
//             if(pmax < height[i]) pmax = height[i];
//             prefmax[i] = pmax;
//         }

//         int smax = 0;
//         for(int i=n-1; i>=0; i--){
//             if(smax < height[i]) smax = height[i];
//             sufmax[i] = smax;
//         }
        
//         int ans = 0;
//         for(int i=0; i<n; i++){
//             ans += min(prefmax[i], sufmax[i]) - height[i]; 
//         }
//         return ans;
        int l = 0;
        int r = n-1;
        int leftmax = 0;
        int rightmax = 0;
        int ans = 0;
        
        while(l<r){
            if(height[l] <= height[r]){
                if(height[l] >= leftmax) leftmax = height[l];
                else ans += leftmax - height[l];
                l++;
            }
            else{
                if(height[r] >= rightmax) rightmax = height[r];
                else ans += rightmax - height[r];
                r--;
            }
        }
        return ans;
    }
};