class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>s;
        string ans = "";

        for(auto n : num){
            while(k>0 && !s.empty() && s.top() > n){
                k--;
                s.pop();
            }
            s.push(n);
        }
        while(k>0 && !s.empty()){
            s.pop();
            k--;
        }

        while(!s.empty()){
            ans += s.top();
            s.pop();
        }

        int end = 0;
        for(int i=ans.size()-1; i>=0; i--){
            if(ans[i] != '0'){
                end = i;
                break;
            }
        }
        ans = ans.substr(0, end+1);
        reverse(ans.begin(), ans.end());

        // long long start = ans.size();
        // for(long long i=0; i<ans.size(); i++){
        //     if(ans[i] != '0'){
        //         start = i;
        //         break;
        //     }
        // }
        // // if(rem){
        // //     ans.erase(0,rem);
        // // }
        // long long n = ans.size();
        // ans = ans.substr(start, n-start);

        if(ans == "") return "0";
        return ans;
    }
};