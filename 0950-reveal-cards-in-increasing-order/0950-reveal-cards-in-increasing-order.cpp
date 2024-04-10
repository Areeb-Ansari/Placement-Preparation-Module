class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int>ans(n);
        sort(deck.begin(), deck.end());
        queue<int>q;
        for(int i=0; i<n; i++) q.push(i);

        for(auto x : deck){
            int i = q.front();
            q.pop();
            ans[i] = x;

            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return ans;

    }
};