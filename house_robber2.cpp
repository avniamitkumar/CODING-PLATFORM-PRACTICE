class Solution {
public:
   int solve(vector<int>&arr,int ind,vector<int>&dp)
    {
        if(ind==0)
        {
            return arr[0];
        }
        if(ind<0)return 0;
        int take=INT_MIN;
        int note=INT_MIN;
        if(dp[ind]!=-1)return dp[ind];
         take=arr[ind]+solve(arr,ind-2,dp);
         note=solve(arr,ind-1,dp);
        return dp[ind]=max(take,note);
    }


    int rob(vector<int>& arr) {
        int n=arr.size();
        
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        vector<int>in,ex;
        if(n==1)
        {
            return arr[0];
        }
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                in.push_back(arr[0]);
            }
            else if(i>0 && i<n-1)
            {
                in.push_back(arr[i]);
                ex.push_back(arr[i]);
            }
            else
            {
                 ex.push_back(arr[i]);;
            }
        }
        return max(solve(in,n-2,dp1),solve(ex,n-2,dp2));
    }
};