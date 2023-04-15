//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int fun(int n,int i,vector<int>&dp)
    {
       if(i>=n)
       {
           if(i==n)return 1;
           return 0;
       
       }
       if(dp[i]!=-1)
           return dp[i];
        else
             return (dp[i] = fun(n,i+1,dp)%1000000007 + fun(n,i+2,dp)%1000000007)%1000000007;

    }   
    
    int countWays(int n)
    {
        // your code here
        vector<int>dp(n+1,-1);
        
        return fun(n,0,dp);
        
        
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends