//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
    
	public:
	int solve(int arr[],int ind,int n,int w,vector<vector<int>>&dp)
	{
	     if(w==0)return 0;
	    if(ind>=n && w!=0)
	    {
	        
	        return 1e9;
	    }
	    if(dp[ind][w]!=-1)return dp[ind][w];
	    int tk=INT_MAX,nt=INT_MAX;
	    if(w-ind-1>=0 && arr[ind]!=-1)
	    {
	        tk=arr[ind]+solve(arr,ind,n,w-ind-1,dp);
	    }
	    nt=solve(arr,ind+1,n,w,dp);
	    return dp[ind][w]=min(tk,nt);
	}
	int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        vector<vector<int>>dp(N+1,vector<int>(W+1,-1));
        int ans=solve(cost,0,N,W,dp);
          if(ans >= 1e9) return -1;
        return ans;
        
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends