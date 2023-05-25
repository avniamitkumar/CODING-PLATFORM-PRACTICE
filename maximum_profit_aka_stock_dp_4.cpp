//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int arr[],int n,int ind,int cap,int buy,vector<vector<vector<int>>>&dp)
    {
        if(ind==n || cap==0)return 0;
        int profit=0;
        if(dp[ind][buy][cap]!=-1)return dp[ind][buy][cap];
        if(buy==1)
        {
            profit=max(-arr[ind]+solve(arr,n,ind+1,cap,0,dp),solve(arr,n,ind+1,cap,1,dp));
        }
        else
        {
            profit=max(arr[ind]+solve(arr,n,ind+1,cap-1,1,dp),solve(arr,n,ind+1,cap,0,dp));
        }
        return dp[ind][buy][cap]=profit;
    }
    int maxProfit(int k, int n, int arr[]) {
        // code here
       // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
          vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=1;cap<=k;cap++)
                {
                    if(buy==1)
                    {
                        dp[ind][buy][cap]=max(-arr[ind]+dp[ind+1][0][cap],dp[ind+1][1][cap]);
                    }
                    else
                    {
                        dp[ind][buy][cap]=max(arr[ind]+dp[ind+1][1][cap-1],dp[ind+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][k];
      //  return solve(arr,n,0,k,1,dp);
        
    }
    /*
    //Space Optimization

int maxProfit(int K, int n, int prices[]) {
        vector<vector<int>> prev(2,vector<int>(K+1,0)),curr(2,vector<int>(K+1,0));
        for(int ind =n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=K;cap++){
                    if(buy){
                        curr[buy][cap]= max(-prices[ind]+prev[0][cap],prev[1][cap]);
                    }
                    else{
                        curr[buy][cap]= max(prices[ind]+prev[1][cap-1],prev[0][cap]);
                    }
                    
                }
            }
            prev=curr;
        }
        return prev[1][K];
    }*/
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends