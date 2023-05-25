//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
//RECURSION
int solve(vector<int>&price,int ind,int n,int cap,int buy)
{
    if(ind==n ||  cap==0)return 0;
    int profit=0;
    if(buy==1)
    {
        profit=max((-price[ind]+solve(price,ind+1,n,cap,0)),solve(price,ind+1,n,cap,1));
    }
    else{
        profit= max(price[ind]+solve(price,ind+1,n,cap-1,1),solve(price,ind+1,n,cap,0));
    }
    return profit;
}
//MEMOIZATION
int solve2(vector<int>&price,int ind,int n,int cap,int buy,vector<vector<vector<int>>>&dp)
{
    if(ind==n ||  cap==0)return 0;
    if(dp[ind][buy][cap]!=-1)return dp[ind][buy][cap];
    int profit=0;
    if(buy==1)
    {
        profit=max((-price[ind]+solve2(price,ind+1,n,cap,0,dp)),solve2(price,ind+1,n,cap,1,dp));
    }
    else{
        profit= max(price[ind]+solve2(price,ind+1,n,cap-1,1,dp),solve2(price,ind+1,n,cap,0,dp));
    }
    return  dp[ind][buy][cap] =profit;
}

int maxProfit(vector<int>&price){
    //Write your code here..
    int n=price.size();
    
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    //TABULATION
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            for(int cap=1;cap<=2;cap++)
            {
                if(buy==1)
                {
                    dp[ind][buy][cap]=max(-price[ind]+dp[ind+1][0][cap],dp[ind+1][1][cap]);
                }
                else
                {
                    dp[ind][buy][cap]=max(price[ind]+dp[ind+1][1][cap-1],dp[ind+1][0][cap]);
                    
                }
            }
        }
        
    }
    return dp[0][1][2];
    
    
    
     return solve2(price,0,price.size(),2,1,dp);
    return solve(price,0,price.size(),2,1);
    
    
    
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends