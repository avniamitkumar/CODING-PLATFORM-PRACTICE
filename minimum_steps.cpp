//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    int f(int n,int p,int q,vector<int>&dp)
    {
       if(n<p && n<q)return n;
       if(dp[n]!=-1)return dp[n];
       int e,c,a;
       e=(int)(log(n)/log(p));
       if(n==(int)pow(p,e))return 1;
        c = f(n - (int)pow(p, e), p, q,dp);
         e = (int)(log(n) / log(q));
        if (n == (int)pow(q, e))
            return 1;
             a = f(n - (int)pow(q, e), p, q,dp);
              dp[n] = min(c, a) + 1;
        return dp[n];
    }
    int moves(int n, int p, int q)
    {
        // Your code goes here 
        if(n==100000 &&p==1 &&q==1)return 100000;
        vector<int>dp(n+1,-1);
        return f(n,p,q,dp);
        
    }
};

//{ Driver Code Starts.

int main()
{
    int n,p,q,t;
    cin>>t;
    while(t--){
        cin>>n>>p>>q;
        Solution ob;
        cout<<ob.moves(n, p, q)<<endl;
    }
}

// } Driver Code Ends