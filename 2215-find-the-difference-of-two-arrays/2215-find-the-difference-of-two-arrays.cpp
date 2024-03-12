class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {  
        // giving repeated elements therefore used SET
        // vector<vector<int>>ans;
        // unordered_map<int, int>mp1;
        // unordered_map<int, int>mp2;

        // for(auto x : nums1) mp1[x]++;
        // for(auto x : nums2) mp2[x]++;

        // vector<int>temp1;
        // for(int i=0; i<nums1.size(); i++){
        //     if(!mp2[nums1[i]]) temp1.push_back(nums1[i]);
        // }
        // ans.push_back(temp1);

        // vector<int>temp2;
        // for(int i=0; i<nums2.size(); i++){
        //     if(!mp1[nums2[i]]) temp2.push_back(nums2[i]);
        // }
        // ans.push_back(temp2);
        // return ans;

        vector<vector<int>>ans;
        unordered_set<int>s1(nums1.begin(), nums1.end());
        unordered_set<int>s2(nums2.begin(), nums2.end());
        vector<int>temp1;
        vector<int>temp2;

        for(auto x : s1){
            if(!s2.count(x)) temp1.push_back(x);
        }
        ans.push_back(temp1);

        for(auto x : s2){
            if(!s1.count(x)) temp2.push_back(x);
        }
        ans.push_back(temp2);

        return ans;
    }
};