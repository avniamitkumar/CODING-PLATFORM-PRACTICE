//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  int solve(vector<int>&arr,int ind,vector<int>&dp)
  {
      if(ind==0)return arr[0];
      if(ind<0)return 0;
      if(ind==1)return arr[0]+arr[1];
      if(dp[ind]!=-1)return dp[ind];
      int take=INT_MIN,no=INT_MIN;
      int c3=INT_MIN;
      
          take=arr[ind]+solve(arr,ind-2,dp);
      
      c3=solve(arr,ind-3,dp)+arr[ind]+arr[ind-1];
      no=0+solve(arr,ind-1,dp);
      return dp[ind]=max(c3,max(take,no));
  }
  
  
  
  int findMaxSum(vector<int>& a){
      //Code Here
      int n=a.size();
      vector<int>dp(n,-1);
      return solve(a,n-1,dp);
  }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.findMaxSum(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends