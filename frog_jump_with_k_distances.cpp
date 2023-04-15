//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  //MEMOIZATION
    int solve(vector<int>&arr,vector<int>&dp,int ind,int k)
    {
        int mini=INT_MAX;;
        if(ind==0)
        {
            return mini=dp[0]=0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        for(int i=1;i<=k;i++)
        {
            if(ind-i>=0)
            {
                int jump=solve(arr,dp,ind-i,k)+abs(arr[ind]-arr[ind-i]);
                mini=min(mini,jump);
                
            }
            
        }
        return dp[ind]=mini;
    }
    //TABULATION
    int solve2(vector<int>&arr,vector<int>&dp,int ind,int k)
    {
        
        dp[0]=0;
        for(int i=1;i<ind;i++)
        {
            int mini=INT_MAX;
            for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            {
                int jump=dp[i-j]+abs(arr[i]-arr[i-j]);
                mini=min(mini,jump);
                
            }
            
        }
            dp[i] = mini;
        }
            return dp[ind-1];
    }
    
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int>dp(n+1,-1);
        int ans=solve2(height,dp,n,k);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends