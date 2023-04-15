//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
     //Function to return max value that can be put in knapsack of capacity W.
    /*int knapSack(int W, int wt[], int val[], int n) 

    { 

       // Your code here
        
       if(n<=0 || W<=0){

           return 0;

       }

      

       if(wt[n-1]<=W)

       {

          return max(knapSack(W,wt,val,n-1),knapSack(W-wt[n-1],wt,val,n-1)+val[n-1]);

       }

       

        return knapSack(W,wt,val,n-1);

       

    }*/
    //Function to return max value that can be put in knapsack of capacity W.
    
    //recursion+memoization
    int solve(int w,int wt[],int val[],int ind,vector<vector<int>>&dp)
    {
        if(ind==0)
        {
            if(wt[0]<=w)return val[0];
            else return 0;
        }
        if(dp[ind][w]!=-1)return dp[ind][w];
        int nt=0+solve(w,wt,val,ind-1,dp);
        int tk=INT_MIN;
        if(wt[ind]<=w)
        {
            tk=val[ind]+solve(w-wt[ind],wt,val,ind-1,dp);
        }
        return dp[ind][w]=max(tk,nt);
        
        
    }
    //TABULATION
    /*int knapSack(int W, int wt[], int val[], int n) 
    { 
        int dp[1001][1001];
       for(int i=0;i<=W;i++){
           dp[0][i] =0;
       }
       for(int j=0; j<=n;j++){
           dp[j][0] =0;
       }
       for(int i=1;i<=n;i++){
           for(int j=1;j<=W;j++){
               if(wt[i-1]<=j){
                   dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
               }
               else{
                   dp[i][j] = dp[i-1][j];
               }
           }
       }
       return dp[n][W];
    }
};
    */
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n,vector<int>(W+1,-1));
       return solve(W,wt,val,n-1,dp);
       
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends