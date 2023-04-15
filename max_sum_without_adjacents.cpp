//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int solve(int *arr,int n,vector<int>&dp)
	{
	    if(n<0)
	    {
	        return 0;
	    }
	    if(n==0)
	    {
	        return arr[0];
	    }
	     if(dp[n]!=-1){

        return dp[n];

    }   
	    int a=solve(arr,n-2,dp)+arr[n];
	    int b=solve(arr,n-1,dp)+0;
	    return    dp[n]=max(a,b);
	    
	}
	
	
	int findMaxSum(int *arr, int n) {
	    // code here
	    int sum=0;   vector<int>dp(n,-1);
	    return solve(arr,n-1,dp);
	    return sum;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends