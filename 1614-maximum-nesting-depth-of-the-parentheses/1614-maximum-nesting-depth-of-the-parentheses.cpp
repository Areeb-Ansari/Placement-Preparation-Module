class Solution {
public:
    int maxDepth(string s) {
        stack<int>st;
        int ans = 0;

        for(auto x : s){
            if(st.empty()){
                if(x=='(' || x==')') st.push(x);
            }
            else if(x=='(' || x==')'){
                int currsize = st.size();
                ans = max(ans, currsize);
                if(st.top() == '(' && x == ')') st.pop();
                else st.push(x);
            }
        }
        return  ans;
    }
};