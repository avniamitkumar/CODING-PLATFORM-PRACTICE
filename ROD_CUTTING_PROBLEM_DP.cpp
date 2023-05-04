//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutrod(int price[],int ind,int n,vector<vector<int>>&dp)
    {
        if(ind==0)
        {
            return n*price[0];
        }
        if(dp[ind][n]!=-1)return dp[ind][n];
        int nc=cutrod(price,ind-1,n,dp);
        int c=INT_MIN;
        if(ind+1<=n)
        {
            c=price[ind]+cutrod(price,ind,n-ind-1,dp);
        }
        return dp[ind][n]=max(c,nc);
        
    }
  
    //TABULATION
    /*
    
    class Solution{
  public:
    int cutRod(int price[], int n) {
        int len[n];
        for(int i=0;i<n;i++) len[i] = i + 1;
        
        int t[n+1][n+1];
        
        for(int i=0;i<n+1;i++){
            t[i][0] = 0;
            t[0][i] = 0;
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(len[i-1] <= j){
                    t[i][j] = max(price[i-1]+t[i][j-len[i-1]], t[i-1][j]);
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][n];
    }
};
    */
    int cutRod(int price[], int n) {
        //code here
     vector<vector<int>>dp(n,vector<int>(n+1,-1));
    return cutrod(price,n-1,n,dp);
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends