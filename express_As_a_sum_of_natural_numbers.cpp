//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int solve(int ind,int tar,int x,vector<vector<int>>&dp)
    {
        if(tar==0)
        {
            return 1;
        }
        if(tar<0) return 0;
        if(pow(ind,x)>tar)  return 0;
        
        //if(ind<=0)return 0;
        if(dp[ind][tar]!=-1)return dp[ind][tar];
        long long int t=pow(ind,x);
        int pick=0;
        if(tar-t>=0)
        {
            pick=solve(ind+1,tar-t,x,dp);
        }
        int notpick=solve(ind+1,tar,x,dp);
        return dp[ind][tar]=(pick + notpick) % (int)(1e9 + 7);
    }
    
    
    
    int numOfWays(int n, int x)
    {
        // code here
      //  int maxLimit=pow(n,1.0/x);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(1,n,x,dp);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends