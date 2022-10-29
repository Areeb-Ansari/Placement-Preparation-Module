//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int least_average(vector<int>nums, int k)
	{
	    int n = nums.size();
	    // Code here
	    int index = 1;
	    int minsum = 0;
	    
	    int currsum = 0;
	    for(int i=0; i<k; i++){
	        currsum += nums[i];
	    }
	    minsum = currsum;
	    
	    for(int i=k; i<n; i++){
	        currsum = currsum + nums[i] - nums[i-k];
	        
	        if(currsum < minsum){
	            minsum = currsum;
	            index = i-k+2;
	        }
	    }
	    return index;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
		cin >> n >> k;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.least_average(nums, k);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends