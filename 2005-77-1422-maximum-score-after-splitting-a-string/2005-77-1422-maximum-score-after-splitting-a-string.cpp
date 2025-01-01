class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int one = 0;
        int zero = 0;
        int ans = 0;
        int currscore = 0;
        vector<int>pre(n);

        for(int i=n-1; i>=0; i--){
            if(s[i] == '1'){
                one++;
                pre[i] = one;
            }
        }

        for(int i=0; i<n-1; i++){
            if(s[i] == '0') zero++;
            currscore = zero + pre[i+1];
            ans = max(ans, currscore);
        }
        return ans;


        // int n = s.size();
        // int zero = 0;
        // int one = 0;
        // int ans = 0;
        // vector<int>left(n);
        // vector<int>right(n);

        // for(int i=0; i<n; i++){
        //     if(s[i] == '0'){
        //         zero++;
        //         left[i] = zero;
        //     }
        // }

        // for(int i=n-1; i>=0; i--){
        //     if(s[i] == '1'){
        //         one++;
        //         right[i] = one;
        //     }
        // }

        // int currscore = 0;
        // for(int i=0; i<n-1; i++){
        //     currscore = left[i] + right[i+1];
        //     ans = max(ans,currscore);
        // }
        // return ans;
    }
};