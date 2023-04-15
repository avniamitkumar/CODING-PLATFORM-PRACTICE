//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mode=1e9+7;
  
  //MEMOIZATION
    int solve(int n,int m,vector<vector<int>>& grid,vector<vector<int>>&dp)
    {
        if(n>=0 &&m>=0 && grid[n][m]==1)
        {
            return 0;
        }
        if(n==0 && m==0) return 1;

        if(n<0||m<0) return 0;
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        
        int a=solve(n-1,m,grid,dp);
        int b=solve(n,m-1,grid,dp);
        
        return dp[n][m]=(a+b)%mode;
    }
    //TABULATION
    int solve2(int n,int m,vector<vector<int>>& grid)
    {
        int dp[n][m];
        if(n>=0 &&m>=0 && grid[n][m]==1)
        {
        return 0;
        }
        if(n==0 && m==0) return dp[0][0]=1;

        if(n<0||m<0) return 0        ;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int a=dp[i-1][j];
                int b=dp[i][j-1];
                dp[i][j]=a+b;
            }
        }
        
        return dp[n-1][m-1];
    }
    
    
    
  
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        //return solve(n,m,grid);
       //  vector<vector<int>> dp(n,vector<int>(m,-1));
return solve2(n,m,grid);
      // return solve(n-1,m-1,grid,dp)%mode;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends