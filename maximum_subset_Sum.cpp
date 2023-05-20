//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
    long long solve(int n,vector<int>&arr,int ind,bool prev,vector<vector<long long>>& dp)
    {
        if(ind>=n)
        {
            return 0;
        }
        //if(ind<0)return 0;
        if(dp[ind][prev]!=-1)return dp[ind][prev];
        long long ans;
        if(prev==false)
        {
            ans=max(solve(n,arr,ind+1,true,dp),arr[ind]+solve(n,arr,ind+1,false,dp));
        }else
        {
            ans=arr[ind]+solve(n,arr,ind+1,false,dp);
        }
        return dp[ind][prev]=ans;
    }
  
  
  
    long long findMaxSubsetSum(int n, vector<int> &arr) {
        // code here
        vector<vector<long long>>dp(n+1,vector<long long>(2,-1));
       // vector<int>dp(n,-1);
        return solve(n,arr,0,false,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends