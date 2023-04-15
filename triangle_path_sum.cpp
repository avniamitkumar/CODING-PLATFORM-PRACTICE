//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   int dp[300][300];
    int solve(int i,int j,int n,vector<vector<int>>& triangle)
    {
        if(i==n)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int sm=solve(i+1,j,n,triangle);
        int dia=solve(i+1,j+1,n,triangle);
        return dp[i][j]=triangle[i][j]+min(sm,dia);
    }
  
  
    
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        // Code here
        memset(dp,-1,sizeof(dp));

        return solve(0,0,n,triangle);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends