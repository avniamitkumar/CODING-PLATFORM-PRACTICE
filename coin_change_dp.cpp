//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  //RECURSION+MEMOIZATION
    long long int f(int coins[],int sum,int ind,vector<vector<int>>&dp)
    {
        if(sum==0)return 1;
        if(sum<0 || ind<0)return 0;
      
        if(dp[ind][sum]!=-1)return dp[ind][sum];
        long long int nt=0+f(coins,sum,ind-1,dp);
        long long int tk=0;
        if(coins[ind]<=sum)
        {
            tk=f(coins,sum-coins[ind],ind,dp);
        }
        dp[ind][sum]= nt+tk;
        return nt+tk;
        
    }
    //TABULATION
    /*
    
      // tabulation solution...
        
        long long dp[sum+1][N+1];
        for(int i=0;i<=N;i++)dp[0][i]=1;
        for(int i=1;i<=sum;i++)dp[i][0]=0;
        
        for(int i=1;i<=sum;i++)
        {
            for(int j=1;j<=N;j++)
            {
                dp[i][j]=dp[i][j-1];
                if(coins[j-1]<=i)
                dp[i][j]=dp[i][j]+dp[i-coins[j-1]][j];
            }
        }
        return dp[sum][N];
    
    */
  
  
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<int>>dp(N,vector<int>(sum+1,-1));
        return f(coins,sum,N-1,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends