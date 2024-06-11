class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        //unordered_set<int>temp(arr2.begin(), arr2.end());
        vector<int>ans;
        vector<int>freq(1001);
        for(int i=0; i<arr1.size(); i++){
            freq[arr1[i]]++;
        }

        for(int n : arr2){
            int f = freq[n];
            while(f--) ans.push_back(n);
            freq[n] = 0;
        }

        for(int i=0; i<1001; i++){
            int f = freq[i];
            while(f--) ans.push_back(i);
        }

        return ans;
    }
};