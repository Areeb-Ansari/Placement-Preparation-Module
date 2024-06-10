class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // int ans = 0;
        // vector<int>exp = heights;
        // sort(exp.begin(), exp.end());

        // for(int i=0; i<heights.size(); i++){
        //     if(heights[i] != exp[i]) ans++;
        // }
        // return ans;

        //solution - 2
        int ans = 0;
        vector<int>exp;
        vector<int>freq(101);
        for(int i=0; i<heights.size(); i++){
            freq[heights[i]]++;
        }

        for(int i=1; i<101; i++){
            int f = freq[i];
            while(f--){
                exp.push_back(i);
            }
        }

        for(int i=0; i<heights.size(); i++){
            if(heights[i] != exp[i]) ans++;
        }
        return ans;
    }
};