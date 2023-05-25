//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return maximum XOR subset in set[]

class Solution
{
    public:
    
    int solve(int arr[],int n,int pxor,int ind,vector<vector<int>>&dp)
    {
        if(ind==n)
        {
           
            return pxor;
        }
        if(dp[pxor][ind]!=-1)return dp[pxor][ind];
        int tk=0,nt=0;
        tk=solve(arr,n,pxor^arr[ind],ind+1,dp);
        nt=solve(arr,n,pxor,ind+1,dp);
        return dp[pxor][ind]=max(tk,nt);
        
    }

    int maxSubsetXOR(int arr[], int N)
    {
        //Your code here
        
 /*       int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,arr[i]);
        }
          int M=pow(2,log2(maxi)+1);
        vector<vector<int>>dp(M,vector<int>(n+1,-1));
        return solve(arr,n,0,0,dp);*/
        if(N == 0) return 0;
int x = 0;
while(1)
{
  int y = *max_element(arr,arr+N);
  if(y == 0) return x;
  x = max(x,x^y);
  for(int i=0;i<N;i++)
  {
    arr[i] = min(arr[i],arr[i]^y);
  }
}
        
    }
};

//{ Driver Code Starts.
int main()
{

    int t,n,a[100004],k;
    scanf("%d",&t);
    while(t--)
    {
        //cin>>n;
       scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        Solution obj;
        printf("%d\n",obj.maxSubsetXOR(a,n));
       // cout<<bin(a,0,n-1,k)<<endl;
    }
}
// } Driver Code Ends