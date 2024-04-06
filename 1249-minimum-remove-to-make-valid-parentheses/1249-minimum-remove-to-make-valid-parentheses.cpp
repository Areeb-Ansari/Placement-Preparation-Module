class Solution {
public:
    string minRemoveToMakeValid(string s) {
        //solution 1
        // stack<pair<char,int>>st;
        // priority_queue<int>pq;

        // for(int i=0; i<s.size(); i++){
        //     if(st.empty()){
        //         if(s[i]=='(' || s[i]==')') st.push({s[i],i});
        //     } 
        //     else if(st.top().first=='(' && s[i]==')'){
        //         st.pop();
        //     }
        //     else if(s[i]=='(' || s[i]==')') st.push({s[i],i});
        // }

        // while(!st.empty()){
        //     int i = st.top().second;
        //     st.pop();
        //     pq.push(i);
        // }

        // while(!pq.empty()){
        //     int i = pq.top();
        //     pq.pop();
        //     s.erase(i,1);
        // }
        // return s;

        //solutions 2

        string res;
        int count = 0; //for count of (
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                res.push_back(s[i]);
                count++;
            }
            else if(s[i]==')' && count>0){
                res.push_back(s[i]);
                count--;
            }
            else if(s[i] != ')') res.push_back(s[i]);
        }

        for(int i=res.size()-1; i>=0; i--){
            if(res[i]=='(' && count>0){
                count--;
                res.erase(i,1);
            }
        }
        return res;
    }
};