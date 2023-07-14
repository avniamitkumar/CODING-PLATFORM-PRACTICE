//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(string &s,int i,int j)
    {
          while(i<j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    int solve(string &str,int ind,vector<int>&dp)
    {
        if(ind==str.size())return 0;
        int partition=0;
        int mini=INT_MAX;
        if(dp[ind]!=-1)return dp[ind];
        for(int i=ind;i<str.size();i++)
        {
            if(isPalindrome(str,ind,i))
            {
                partition=1+solve(str,i+1,dp);
            }
             mini=min(partition,mini);
        }
       return dp[ind]=mini;
        
    }


    int palindromicPartition(string str)
    {
        // code here
      //  int maxi=str.size()-1;
      int n=str.size();
      vector<int>dp(str.size(),-1);
            return solve(str, 0,dp)-1;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends