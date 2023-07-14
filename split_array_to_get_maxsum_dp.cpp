class Solution {
public:
    vector<vector<int>>dp;
    int f(int ind,int k,vector<int>&v)
    {
        if(k==0)
        {
            int sum=0;
            for(int i=ind;i<v.size();i++)
            {
                sum+=v[i];
            }
            return sum;
        }
        if(dp[ind][k]!=-1)return dp[ind][k];
        int ans=INT_MAX;
        int s=0;
        for(int i=ind;i<v.size();i++)
        {
            s+=v[i];
            ans=min(ans,max(s,f(i+1,k-1,v)));
        }
                return dp[ind][k]=ans;

    }
    int splitArray(vector<int>&v, int k) {
        int n=v.size();
        dp=vector<vector<int>>(n+1,vector<int>(k+1,-1));
        return f(0,k-1,v);
    }
};