//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	const int MOD= 1e9+7;
	
	ll solve(bool flag,int n,int idx,vector<vector<ll>>&dp)
	{
	    if(idx<0) return 1;
	    
	    if(dp[flag][idx]!= -1) return dp[flag][idx];
	    
	    if(flag==true)
	    {
	        ll op1= solve(true,n,idx-1,dp);
	        ll op2= solve(false,n,idx-1,dp);
	        return dp[flag][idx]=(op1%MOD+op2%MOD)%MOD;
	        
	    }
	    else{
	        ll op1= solve(true,n,idx-1,dp);
	        
	        return dp[flag][idx]= (op1)%MOD;
	        
	    }
	}
	ll countStrings(int n) {
	    // code here
	    vector<vector<long long>>dp(2,vector<ll>(n,-1));
	    bool flag= true;
	    return solve(flag,n,n-1,dp);
	    
		}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends