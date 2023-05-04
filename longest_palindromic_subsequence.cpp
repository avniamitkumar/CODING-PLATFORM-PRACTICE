//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int solve(string s,int i,int j,vector<vector<int>>&dp)
    {
        if(i==j)return 1;
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j])
        {
            return dp[i][j]=2+solve(s,i+1,j-1,dp);
        }
        else
        {
            return dp[i][j]=max(solve(s,i+1,j,dp),solve(s,i,j-1,dp));
        }
        
    }
    int longestPalinSubseq(string A) {
        int n=A.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(A,0,n-1,dp);
        
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends