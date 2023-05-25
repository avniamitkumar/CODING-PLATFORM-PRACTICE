//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long solve(vector<long long>&prices,int n,int ind,int buy,vector<vector<long long >>&dp)
    {
        if(ind>=n)return 0;
        long long profit=0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        if(buy==1)
        {
            profit=max(-prices[ind]+solve(prices,n,ind+1,0,dp),solve(prices,n,ind+1,1,dp));
        }
        else
        {
          profit=max(prices[ind]+solve(prices,n,ind+2,1,dp),solve(prices,n,ind+1,0,dp));   
        }
        return dp[ind][buy]=profit;
    }
    
    
    
    
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
     //.  vector<vector<long long>>dp(n+1,vector<long long>(2,-1));
      // vector<vector<long long>>dp(n+1,vector<long long>(2,0));
        vector<vector<long long>>dp(n+2,vector<long long>(2,0));
        dp[n][0]=dp[n][1]=0;
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int b=0;b<=1;b++)
            {
                long long profit=0;
                if(b)
                {
                    profit=max((-prices[ind]+dp[ind+1][0]),dp[ind+1][1]);
                }
                    else
                    {
                        profit=max((prices[ind]+dp[ind+2][1]),dp[ind+1][0]);
                    }
            dp[ind][b]=profit;}
        }
        
        
        return dp[0][1];
        
       
       // return solve(prices,n,0,1,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends