class Solution {
public:
    int pivotInteger(int n) {
        // vector<int>pre(n+1);
        // vector<int>post(n+1);

        // for(int i=1; i<=n; i++){
        //     pre[i] = pre[i-1] + i;
        // }

        // post[n] = n;
        // for(int i=n-1; i>=1; i--){
        //     post[i] = post[i+1] + i;
        // }

        // for(int i=1; i<=n; i++){
        //     if(pre[i] == post[i]) return i;
        // }
        // return -1;

        int sum = n*(n+1)/2;
        double t = sqrt(sum);

        if(t - ceil(t) == 0) return t;
        else return -1;
    }
};