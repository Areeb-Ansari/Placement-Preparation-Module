class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        string ans;

        for(auto str : s){
            if(st.empty()) st.push(str);
            else if(str=='*'){
                st.pop();
            }
            else st.push(str);
        }
        
        while(!st.empty()){
            char c = st.top();
            st.pop();
            ans.insert(0, string(1,c));
        }
        return ans;
    }
};