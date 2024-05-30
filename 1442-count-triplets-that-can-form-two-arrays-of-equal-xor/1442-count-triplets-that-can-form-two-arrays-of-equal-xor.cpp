class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        vector<int> prefixor(n+1, 0);
        for(int i=0; i<n; i++){
            prefixor[i+1] = prefixor[i] ^ arr[i];
        }

        for(int i=0; i<n; i++){
            for(int k=i+1; k<=n; k++){
                if(prefixor[i] == prefixor[k]){
                    ans += k-(i+1);
                }
            }
        }
        return ans;
    }
};