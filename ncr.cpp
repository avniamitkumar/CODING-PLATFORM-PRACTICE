//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
int mod=1e9+7;
class Solution{
public:
    long long int solve(int n,int r,vector<vector<int>>&dp)
    {
        if(r==0 || r==n)return 1;
        if(r==1 || r==n-1)return n;
        if(n<r)return 0;
        
        if(dp[n][r]!=-1)return dp[n][r];
        long long int a=solve(n-1,r,dp);
        long long int b=solve(n-1,r-1,dp);
        return dp[n][r]=(a+b)%mod;
    }




    int nCr(int n, int r){
        // code here
        vector<vector<int>>dp(n+1,vector<int>(r+1,-1));
        return solve(n,r,dp);
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends