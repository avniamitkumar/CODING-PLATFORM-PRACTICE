//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   int solve(int N, vector<vector<int>>&Matrix, vector<vector<int>>&dp, int row, int col)
    {
        if(row>=N||col>=N)
        return 0;
        if(row==N-1)
        return Matrix[N-1][col];
        
        if(dp[row][col]!=-1)
        return dp[row][col];
        
        int x=solve(N,Matrix,dp,row+1,col);
        int y=solve(N,Matrix,dp,row+1,col-1);
        int z=solve(N,Matrix,dp,row+1,col+1);
        
        dp[row][col]=Matrix[row][col]+max(x,max(y,z));
        return dp[row][col];
    }


    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
         vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
        int ans=INT_MIN;
        for(int i=0; i<N; i++)//variable starting and ending point.We begin from row 0 any column and end it at the last row N-1.
        {
            ans=max(ans,solve(N,Matrix,dp,0,i));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends