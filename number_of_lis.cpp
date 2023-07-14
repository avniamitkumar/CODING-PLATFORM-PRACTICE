//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int NumberofLIS(int n, vector<int>&nums) {
        // Code here
          // int n=nums.size();
        vector<int>dp(n,1),cnt(n,1);
        int maxi=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j] && dp[i]<dp[j]+1)
                {
                   dp[i]=1+dp[j];
                   //inherit like copy
                   cnt[i]=cnt[j];
                }
                else if(nums[i]>nums[j] && dp[i]==dp[j]+1)
                cnt[i]+=cnt[j]; //add the total here comes the same.
            }
            maxi=max(maxi,dp[i]);
        }
       int c=0;
       for(int i=0;i<n;i++)
       {
           if(maxi==dp[i])
           c+=cnt[i];       
       }
       return c;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.NumberofLIS(n, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends