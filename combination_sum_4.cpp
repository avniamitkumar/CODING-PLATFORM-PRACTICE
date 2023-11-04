class Solution {
public:

    int solve(vector<int>&arr,int ind,int target,vector<int>&dp)
    {
        if(target==0)
        {
           return 1;
        }
        if(ind>=arr.size() || target<0 )return 0;
        if(dp[target]!=-1)return dp[target];
        
        int pick=0;
        int npick=0;
        pick=solve(arr,0,target-arr[ind],dp);
        npick=solve(arr,ind+1,target,dp);
        return dp[target]=pick+npick;
    }


    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        
        return solve(nums,0,target,dp);
    }
};