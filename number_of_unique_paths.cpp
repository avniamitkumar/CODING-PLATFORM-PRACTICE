//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    //RECURSION
    int solver(int a,int b)
    {
        if(a==0 && b==0)
        {
            return 1;
        }
        if(a<0 || b<0){
		return 0;
	}
        int up=solver(a-1,b);
        int r=solver(a,b-1);
        return up+r;
    }
    //MEMOIZATION
   int MEMO(int a,int b,vector<vector<int>> &dp)
    {
        if(a==0 && b==0)
        {
            return dp[0][0]=1;
        }
        if(a<0 || b<0){
		return 0;
	}
	if(dp[a][b]!=-1)
	{
	    return dp[a][b];
	}
        int up=MEMO(a-1,b,dp);
        int r=MEMO(a,b-1,dp);
        return dp[a][b]=up+r;
    }
    //tabulation
    int dpButtom(int m, int n){
	int dp[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i==0 && j==0){
				dp[0][0]=1;
			}
			else{
				int up=0;
				int left=0;
				if(i>0){
					up = dp[i-1][j];
				}
				if(j>0){
					left = dp[i][j-1];
				}
				dp[i][j]=up+left;
			}
		}
	}
	return dp[m-1][n-1];
}
    
  
    
    int NumberOfPath(int a, int b)
    {
        //code here
        //return solver(a-1,b-1);
       // vector<int>dp(n+1,-1);
       //vector<vector<int>> dp(a, vector<int> (b, -1));
       return dpButtom(a,b);
       // return MEMO(a-1,b-1,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends