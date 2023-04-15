//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define mod 1000000007
class Solution{

	public:
	int ss(int arr[],int n,int sum,int ind,int s,vector<vector<int>>&dp)
	{
	    if(s>sum)return 0;
	    if(ind>=n)
	    {
	        if(s==sum)
	        {
	         return 1;   
	        }
	        return 0;
	    }
	   // ds.push_back(arr[i]);
	   if(dp[ind][s]!=-1)
	   {
	       return dp[ind][s];
	   }
	    s+=arr[ind];
	    int l=ss(arr,n,sum,ind+1,s,dp);
	    s-=arr[ind];
	   // ds.pop_back();
	    int r=ss(arr,n,sum,ind+1,s,dp);
        return dp[ind][s]=(l+r)%mod;
	    
	}
	
	//TABULATION
	/*
	        vector<vector<int>>(dp,n,vector<int>(sum+1,0));
	        for(int i=0;i<n;i++)dp[i][0]=1;
	        if(arr[0]<=sum)dp[0][arr[0]]=1;
	        if(arr[0]==0)dp[0][arr[0]]=2;
	        for(int i=1;i<n;i++)
	        {
	            for(int tar=0;tar<=sum;tar++)
	            {
	                int nt=dp[i-1][tar];
	                int tk=0;
	                if(arr[i]<=tar)
	                {
	                    tk=dp[i-1][tar-arr[i]];
	                }
	                dp[i][tar]=(tk+nt)%mod;
	            }
	        }
	        return dp[n-1][sum];
	*/
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return ss(arr,n,sum,0,0,dp);
      //  int c=0;
        //int cc=ss(arr,n,sum,0,0,c);
        //return cc%mod;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends