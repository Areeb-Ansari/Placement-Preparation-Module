class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //Solution 1
        int time = 0;
        int count[26] = {0};
        for(auto ch : tasks) count[ch - 'A']++;

        priority_queue<int>pq;
        queue<pair<int, int>>q;
        for(int i=0; i<26; i++){
            if(count[i]) pq.push(count[i]);
        } 

        while(!q.empty() || !pq.empty()){
            time++;
            if(!pq.empty()){
                int task = pq.top() - 1;
                pq.pop();
                if(task>0) q.push({task,time+n}); 
            }

            if(!q.empty() && q.front().second == time){
                int task = q.front().first;
                q.pop();
                pq.push(task);
            }
        }
        return time;

        //Solutions 2
        // int freq[26] = {0};
        // for(char task : tasks){
        //     freq[task - 'A']++;
        // }
        // sort(begin(freq) , end(freq));
        // int chunk = freq[25] - 1;
        // int idel = chunk * n;

        // for(int i=24; i>=0; i--){
        //     idel -= min(chunk,freq[i]);
        // }

        // return idel < 0 ? tasks.size() : tasks.size() + idel;
    }
};