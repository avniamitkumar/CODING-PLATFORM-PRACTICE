//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

//int dp[10001][101];
class Solution {
  public:
    bool solve(int i,int n,int k,int sum,vector<int>&arr,vector<vector<int>>&dp)
    {
        if(sum==0 && k==0)
        {
            return true;
        }
        if(i==arr.size() || k<0)return false;
       //if(n<=0)return false;
       if(dp[k][sum]!=-1)return dp[k][sum];
        bool nt=solve(i+1,n,k,sum,arr,dp);
        bool tk=false;
        if(sum>=arr[i])
        {
            tk=solve(i,n,k-1,sum-arr[i],arr,dp);
        }
        
        return dp[k][sum]=tk||nt;
    }
  
  
  
  
  
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        // code here
 vector<vector<int>> dp(K+1, vector<int> (target+1,-1));
        
        return solve(0,N,K,target,coins,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends