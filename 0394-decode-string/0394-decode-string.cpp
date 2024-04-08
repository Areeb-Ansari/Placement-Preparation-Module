class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        string ans = "";

        for(auto str : s){
            if(str != ']') st.push(string(1,str));
            else{
                string sub = "";
                while(!st.empty() && st.top() != "["){
                    sub = st.top() + sub;
                    st.pop();
                }
                st.pop();

                string k = "";
                while(!st.empty() && isdigit(st.top()[0])){
                    k = st.top() + k;
                    st.pop();
                }

                int count = stoi(k);
                string temp = sub;
                for(int i=1; i<count; i++) temp = temp + sub;
                st.push(temp); 
            }
        }
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};