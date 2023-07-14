class Solution {
public:
 int mod = 7+1e9;
    int solve(vector<int>&arr,int curr,int &end,int fuel,vector<vector<int>>&dp)
    {
        int ans=0;
        if(curr==end)
        {
            ans=1;
        }
         if(fuel==0)return ans;
        if(fuel<0)
        {
            return 0;
        }
        
        if(dp[curr][fuel]!=-1)return dp[curr][fuel];
       // int ans=0;
       
        for(int i=0;i<arr.size();i++)
        {
            if(i!=curr && fuel-abs(arr[i]-arr[curr])>=0){
            ans=(ans+(solve(arr,i,end,fuel-abs(arr[i]-arr[curr]),dp))%mod)%mod;   }
        }
        return dp[curr][fuel]=ans%mod;

    }




    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>>dp(locations.size()+1, vector<int>(fuel+1, -1));
        return solve(locations,start,finish,fuel,dp);
    }
};

