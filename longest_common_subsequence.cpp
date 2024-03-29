//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    //RECURSION
    int solve(int x,int y,string s1,string s2)
    {
        if(x<=0 || y<=0)return 0;
        if(s1[x-1]==s2[y-1])return 1+solve(x-1,y-1,s1,s2);
        return max(solve(x-1,y,s1,s2),solve(x,y-1,s1,s2));
        
    }
    //MEMOIZATION
int helper(int x, int y, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if(x<0 || y<0) return 0;
        
        if(dp[x][y]!=-1)
        return dp[x][y];
        
        if(s1[x]==s2[y])
        dp[x][y]=1+ helper( x-1, y-1, s1, s2,dp);
        
        else
        dp[x][y]=max(helper( x-1, y, s1, s2,dp), helper( x, y-1, s1, s2,dp));
        
        return dp[x][y];
    }
    //TABULATION
    
    int lcs(int x, int y, string s1, string s2)
    {
        int dp[n+1][m+1];
        for(int j=0;j<=y;j++)
        dp[0][j]=0;
        for(int i=0;i<=x;i++)
        dp[i][0]=0;
         for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=y;j++)
            {
                if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else 
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
         return dp[x][y];
        
        
        
    }
    
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
           vector<vector<int>> dp(x, vector<int> (y,-1)); 
        
        return helper(x-1,y-1,s1,s2,dp);
        return solve(x,y,s1,s2);
        
        
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends