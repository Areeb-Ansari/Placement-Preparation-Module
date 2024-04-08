class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int ans = students.size();
        unordered_map<int, int>mp;
        for(auto s : students) mp[s]++;

        for(auto s : sandwiches){
            if(mp[s] > 0){
                ans--;
                mp[s]--;
            }
            else return ans;
        }
        return ans;
    }
};