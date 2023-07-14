class Solution {
public:
    int solve(vector<int>&arr,int diff,int ind,int n,vector<vector<int>>&dp)
    {
       if(ind==n)
       {
           if(diff==0)
           {
               return 0;
           }
           return -1e9;
       }
       if(dp[ind][diff+5000]!=-1)return dp[ind][diff+5000];
        int st1=arr[ind]+solve(arr,diff+arr[ind],ind+1,n,dp);
        int st2=solve(arr,diff-arr[ind],ind+1,n,dp);
        int rej=solve(arr,diff,ind+1,n,dp);
        return dp[ind][diff + 5000] = max({st1, st2, rej});

    }


    int tallestBillboard(vector<int>& rods) {
         int n = rods.size();
        vector<vector<int>> dp(n + 1, vector<int>(10001, -1));
        return solve(rods,0,0,n,dp);
    }
};