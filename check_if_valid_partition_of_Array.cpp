class Solution {
public:
    bool solve(vector<int>&arr,int ind,vector<int>&dp)
    {
        if(ind<0)
        {
            return 1;
        }
        if(dp[ind]!=-1)return dp[ind];
        bool a=0;
        bool b=0;
        bool c=0;

        if(ind>0 && arr[ind]==arr[ind-1])
        {
            a=solve(arr,ind-2,dp);
        }
        if(ind>1 && arr[ind]==arr[ind-1] && arr[ind-1]==arr[ind-2])
        {
            b=solve(arr,ind-3,dp);
        }
          if(ind>1 && arr[ind]==arr[ind-1]+1 && arr[ind-1]==arr[ind-2]+1)
        {
            b=solve(arr,ind-3,dp);
        }
        return dp[ind]=a||b||c;

    }

    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(nums,n-1,dp);
    }
};