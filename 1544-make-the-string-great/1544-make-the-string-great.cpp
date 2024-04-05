class Solution {
public:
    string makeGood(string s) {
        string ans;
        int n = s.size();
        stack<int>st;

        for(int i=n-1; i>=0; i--){
            char ch = s[i];
            if(st.empty()) st.push(ch);

            else{
                char t = st.top();
                if((islower(t) && isupper(ch) && toupper(t)==ch) || (isupper(t) && islower(ch) && tolower(t)==ch))
                st.pop();
                else st.push(ch);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};