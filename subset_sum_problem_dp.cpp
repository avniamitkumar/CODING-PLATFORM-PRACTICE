//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    //RECUSRION
    bool solve(vector<int>arr,int sum,int ind,int n)
    {
        if(ind==n)
        {
            if(sum==0)
            {
                return true;
            }
            return false;
        }
        bool pick=solve(arr,sum-arr[ind],ind+1,n);
        bool notp=solve(arr,sum,ind+1,n);
        return pick||notp;
    }
    //MEMOZIATION
    bool solve2(vector<int>arr,int sum,int ind, vector<vector<int>>&dp)
    {
        if(sum==0)
        {
            return true;
        }
        if(ind==0) return (arr[0]==sum);
        if(dp[ind][sum]!=-1)return dp[ind][sum];
        bool no=solve2(arr,sum,ind-1,dp);
        bool tk=false;
        if(sum>=arr[ind])
        {
            tk=solve2(arr,sum-arr[ind],ind-1,dp);
        }
        return dp[ind][sum]=no||tk;
    }
    /*
    v\//User function template for C++

class Solution{   
public:

   
  
    bool isSubsetSum(vector<int>arr, int sum){
        
       int n = arr.size();
       vector<vector<bool>> dp(n+1,vector<bool>(sum+1));
       
       for(int i=0;i<n+1;i++)
       {
           dp[i][0]=true;
       }
       
       for(int j=1;j<sum+1;j++)
       {
           dp[0][j]=false;
       }
      
      
      for(int i=1;i<n+1;i++)
      {
          for(int j=1;j<sum+1;j++)
          {
              if(arr[i-1]<=j)
              {
                  dp[i][j]=  (dp[i-1][j-arr[i-1]] or dp[i-1][j]);
              }
              else
              {
                  dp[i][j]=dp[i-1][j];
              }
          }
      }
      
      return dp[n][sum];
       
    }
};
    */
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
         vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve2(arr,sum,n-1,dp);
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends