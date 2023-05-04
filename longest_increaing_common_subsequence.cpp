//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int solve(int a[],int n,int curr, int prev, vector<vector<int>>&dp)
    {
        if(curr==n)return 0;
        if(dp[curr][prev+1]!=-1)return dp[curr][prev+1];
        int tk=0;
        if(prev==-1 || a[curr]>a[prev])
        {
            tk=1+solve(a,n,curr+1,curr,dp);
        }
        int ntk=0+solve(a,n,curr+1,prev,dp);
        
        return dp[curr][prev+1]=max(tk,ntk);
    }
     // Tabulation 

    

    int funtab(int n ,int a[]){
        vector<vector<int>> dp(n+1, vector<int>(n+1 ,0));
        for(int cur = n-1;cur>=0;cur--){
            for(int prev = cur-1;prev>=-1;prev--){
                int incl = 0;
                if(prev == -1 or a[cur] > a[prev]) incl  = 1+ dp[cur+1][cur+1];
                int excl = 0+ dp[cur+1][prev+1];
                dp[cur][prev+1] = max(incl, excl);
            }
        }
        return dp[0][0];
    }
    
    
    int longestSubsequence(int n, int a[])
    {
       // your code here
          vector<vector<int>>dp(n,vector<int>(n+1,-1));

        return solve(a,n,0,-1,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends