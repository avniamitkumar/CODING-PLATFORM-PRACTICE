class Solution {
public:
    long long solve(int sum,int left,int ind,vector<int>&arr,vector<vector<long long>>&dp)
    {
        if(ind>=2)
        {
            return 0;
        }
        // if(left<c1 || left <c2)
        // {
        //     return o;
        // }
        if(dp[ind][left]!=-1)return dp[ind][left];
        if(left==0)return 0;
        long long tk=0,nt=0;
        if(arr[ind]<=left)
        {
            tk=1+solve(sum,left-arr[ind],ind,arr,dp);
        }
        
        nt=solve(sum,left,ind+1,arr,dp);
        return dp[ind][left]=tk+nt;
    }



    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        vector<int>arr;
        vector<vector<long long>>dp(2,vector<long long>(total+1,-1));
        arr.push_back(cost1);
        arr.push_back(cost2);

        return 1+solve(total,total,0,arr,dp);
    }
};