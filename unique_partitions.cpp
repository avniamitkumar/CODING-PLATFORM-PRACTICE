//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	void solve(int n,vector<int>&ds,vector<vector<int>>&ans,int sum)
	{
	      if (sum == 0) {
       // sort(temp.rbegin(),temp.rend());
        ans.push_back(ds);
        return;
    }
      if (sum < 0 || n <= 0) return;
	    ds.push_back(n);
	    solve(n,ds,ans,sum-n);
	    ds.pop_back();
	    solve(n-1,ds,ans,sum);
	    
	}
    vector<vector<int>> UniquePartitions(int n) {
        // Code here
        vector<vector<int>>ans;
        vector<int>ds;
        solve(n,ds,ans,n);
        sort(ans.rbegin(),ans.rend());
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends