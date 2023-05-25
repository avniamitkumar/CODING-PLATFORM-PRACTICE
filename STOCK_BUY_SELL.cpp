//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
    public:
    //MEMOIZATION
    long long solve(vector<long long>&prices,long long ind,long long n,vector<vector<long long>>&dp,int buy)
    {
        long long profit=0;
        if(ind==n)
        {
            return 0;
        }
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        if(buy)
        {
            profit=max((-prices[ind]+solve(prices,ind+1,n,dp,0)),solve(prices,ind+1,n,dp,1));
        }
        else
        {
            profit=max((prices[ind]+solve(prices,ind+1,n,dp,1)),solve(prices,ind+1,n,dp,0));
        }
        return dp[ind][buy]=profit;
    }
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        //TABULATION
         vector<vector<long long>>dp(n+1,vector<long long>(2,0));
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
                        profit=max((prices[ind]+dp[ind+1][1]),dp[ind+1][0]);
                    }
            dp[ind][b]=profit;}
        }
        
        
        return dp[0][1];
        
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