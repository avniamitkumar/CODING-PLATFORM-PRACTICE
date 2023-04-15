//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  //RECURSION
    int solve(int arr[],int n,int s1,int s2,int ind)
    {
        if(ind==n)
        {
            return abs(s1-s2);
        }
        int p=solve(arr,n,s1+arr[ind],s2,ind+1);
        int np=solve(arr,n,s1,s2+arr[ind],ind+1);
        return min(p,np);
        
    }
  //MEMOIZATION
  int solve2(int arr[],int n,int s1,int s2,int ind,vector<vector<int>>&dp)
  {
      if(ind==n)
      {
          return abs(s1-s2);
      }
      if(dp[ind][abs(s1-s2)]!=-1)return dp[ind][abs(s1-s2)];
      int p=solve2(arr,n,s1+arr[ind],s2,ind+1,dp);
      int np=solve2(arr,n,s1,s2+arr[ind],ind+1,dp);
      return dp[ind][abs(s1-s2)]=min(p,np);
  }
  
  
  
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int tot=0;
	    for(int i=0;i<n;i++)
	    {
	        tot+=arr[i];
	    }
	    int k=tot;
	    vector<vector<int>>dp(n,vector<int>(k+1,-1));
	    return solve2(arr,n,0,0,0,dp);
	    //return solve(arr,n,0,0,0);
	    
	    
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends