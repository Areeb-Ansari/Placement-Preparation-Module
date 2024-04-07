class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // stack<int>st;
        // vector<int>ans;

        // for(auto x : asteroids){
        //     if(st.empty()) st.push(x);
        //     else if(st.top()>0 && x>0 || st.top()<0 && x<0) st.push(x);
        //     else{
        //         while(st.top()>0 && x<0 || st.top()<0 && x>0){
        //             if(abs(x)>abs(st.top())){
        //                 st.pop();
        //             }
        //             if(abs(x)<abs(st.top()))

        //             if(abs(x)==abs(st.top())) st.pop();

        //         }
        //         st.push(x);
        //     }
        // }

        // while(!st.empty()){
        //     ans.push_back(st.top());
        //     st.pop();
        // }
        // int l=0;
        // int r=ans.size()-1;

        // while(l<r){
        //     swap(ans[l], ans[r]);
        //     l++;
        //     r--;
        // }
        // return ans;

        stack<int>st;

        for(auto x : asteroids){
            while(!st.empty() && x<0 && st.top()>0){
                int diff = x + st.top();
                if(diff < 0) st.pop();
                else if(diff >0) x = 0;
                else{
                    x=0;
                    st.pop();
                }
            }
            if(x) st.push(x);
        }
        
        int n = st.size();
        vector<int>ans(n);
        while(!st.empty()){
            ans[n-1] = st.top();
            n--;
            st.pop();
        }
        return ans;
    }
};