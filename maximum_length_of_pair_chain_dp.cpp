class Solution {
public:
    int solve(vector<vector<int>>&pairs,int prev,int ind,vector<vector<int>>& dp)
    {
        if(ind==pairs.size())
        {
            return 0;
        }
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int take=INT_MIN;
        int not_take=INT_MIN;
        if(prev==-1 || pairs[prev][1]<pairs[ind][0] )
        {
            take=1+solve(pairs,ind,ind+1,dp);
        }
        not_take=solve(pairs,prev,ind+1,dp);
        return dp[ind][prev+1]=max(take,not_take);
    }



    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n=pairs.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(pairs,-1,0,dp);
        
    }
};