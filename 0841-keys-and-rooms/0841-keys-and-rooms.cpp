class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>vis(rooms.size(), false);
        vis[0] = true;
        queue<int>q;
        q.push(0);

        while(!q.empty()){
            int key = q.front();
            q.pop();
            for(int i=0; i<rooms[key].size(); i++){
                if(!vis[rooms[key][i]]){ // if is to ensure we do not push the key of room we already visited
                    q.push(rooms[key][i]);
                }  
                vis[rooms[key][i]] = true;
            }
        }
        for(auto x : vis){
            if(!x) return false;
        }
        return true;
    }
};