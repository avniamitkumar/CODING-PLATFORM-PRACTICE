//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:

    
    int solve(vector<int>&arr,int n,int k,int pxor,int ind,vector<vector<int>>&dp)
    {
        if(ind==n)
        {
            if(pxor==k)
            {
                return 1;
            }
            return 0;
        }
        if(dp[ind][pxor]!=-1)return dp[ind][pxor];
        int tk=0,nt=0;
        tk=solve(arr,n,k,pxor^arr[ind],ind+1,dp);
         nt=solve(arr,n,k,pxor,ind+1,dp);
        return dp[ind][pxor]=tk+nt;
        
    }



    int subsetXOR(vector<int> arr, int n, int k) {
        // code here
         int M=pow(2,log2(*max_element(arr.begin(),arr.end()))+1);
        vector<vector<int>>dp(n+1,vector<int>(M,-1));
        return solve(arr,n,k,0,0,dp);
        
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}
// } Driver Code Ends