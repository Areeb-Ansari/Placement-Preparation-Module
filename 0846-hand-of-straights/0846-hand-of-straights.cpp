class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0) return false;

        map<int, int>mp;
        for(auto h : hand) mp[h]++;

        for(auto [h, freq] : mp){
            if(freq == 0) continue;
            while(freq--){
                for(int curr = h; curr < h+groupSize; curr++){
                    if(mp[curr] == 0) return false;
                    mp[curr]--;
                }
            }
        }
        return true;
    }
};