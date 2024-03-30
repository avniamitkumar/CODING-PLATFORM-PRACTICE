//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int solve(int i,int j,int k,string &s,string &t,string &z,vector<vector<vector<int>>>&dp)
    {
        if(i<0 || j<0 || k<0)return 0;
        int ans=0;
       if(dp[i][j][k]!=-1)return dp[i][j][k];
        if(s[i]==t[j] && t[j]==z[k])
        {
            ans=1+solve(i-1,j-1,k-1,s,t,z,dp);
        }
        else{
            ans=max(solve(i-1,j,k,s,t,z,dp),max(solve(i,j-1,k,s,t,z,dp),solve(i,j,k-1,s,t,z,dp)));
        }
        return dp[i][j][k]=ans;
    }
        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            // your code here
              vector<vector<vector<int>>>dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,-1)));
            return solve(n1-1,n2-1,n3-1,A,B,C,dp);
        }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends