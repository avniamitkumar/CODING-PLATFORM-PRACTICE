//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int n,int w,int val[],int wt[],vector<vector<int>>&dp)
    {
        if(n==0)
        {
            if(wt[0]<=w)return val[0]*(w/wt[0]);
            else return 0;
        }
        if(dp[n][w]!=-1)return dp[n][w];
        int nt=0+f(n-1,w,val,wt,dp);
        int tk=INT_MIN;
        if(wt[n]<=w)
        {
            tk=val[n]+f(n,w-wt[n],val,wt,dp);
        }
        return dp[n][w]=max(tk,nt);
        
    }
    // // tabulation ....
        
        // vector<vector<int>> dp(n, vector<int>(W+1,0));
        // for(int j=0;j<=W;j++) dp[0][j]= val[0]*(j/wt[0]);
        
        // for(int i=1;i<n;i++)
        // {
        //     for(int j=0;j<=W;j++)
        //     {
        //         int pick= INT_MIN;
        //         if(wt[i]<=j) pick= val[i] + dp[i][j-wt[i]];
                 
        //         int nonpick= 0 + dp[i-1][j]; 
                
        //         dp[i][j]= max(pick,nonpick);
        //     }
        // }
        
        // return dp[n-1][W];
        

    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        return f(N-1,W,val,wt,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends