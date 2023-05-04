//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int lcs(int x, int y, string s1, string s2)
    {
        int dp[x+1][y+1];
        for(int j=0;j<=y;j++)
        dp[0][j]=0;
        for(int i=0;i<=x;i++)
        dp[i][0]=0;
         for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=y;j++)
            {
                if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
                else 
                //dp[i][j]=(min(min(dp[i-1][j],dp[i][j-1])),dp[i-1][j-1]);
                 dp[i][j]=1+min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
            }
        }
         return dp[x][y];
        
        
        
    }
    int editDistance(string str1, string str2) {
        // Code here
        int x=str1.size();
        int y=str2.size();
      int dp[x+1][y+1];
        for(int j=0;j<=y;j++)
        dp[0][j]=j;
        for(int i=0;i<=x;i++)
        dp[i][0]=i;
         for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=y;j++)
            {
                if(str1[i-1]==str2[j-1])
                dp[i][j]=dp[i-1][j-1];
                else 
                //dp[i][j]=(min(min(dp[i-1][j],dp[i][j-1])),dp[i-1][j-1]);
                  dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            }
        }
         return dp[x][y];
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends