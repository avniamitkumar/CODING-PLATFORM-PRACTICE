//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        // Code here
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
                        profit=max((prices[ind]+dp[ind+1][1]-fee),dp[ind+1][0]);
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
        
        int fee; cin>>fee;
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n, fee)<<"\n";
    }
    return 0;
}
// } Driver Code Ends