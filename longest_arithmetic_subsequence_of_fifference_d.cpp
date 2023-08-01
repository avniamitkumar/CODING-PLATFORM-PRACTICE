class Solution {
public:
//MEMOIAZATION && RECURSION ----------> TLE
    // int solve(vector<int>&arr,int ind,int diff,int prev,vector<vector<int>>& dp)
    // {
    //     if(ind>=arr.size())
    //     {
    //         return 0;
    //     }
    // if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];
    //     int tk=0;
    //     int nt=0;
    //     if(prev==-1 || arr[ind]-arr[prev]==diff)
    //     {
    //         tk=1+solve(arr,ind+1,diff,ind,dp);
    //     }
    //     nt=solve(arr,ind+1,diff,prev,dp);
    //     return dp[ind][prev+1]=max(nt,tk);
    // }


    int longestSubsequence(vector<int>& arr, int difference) {
    //     int a=*max_element(arr.begin(),arr.end());
         int n=arr.size();
    //      vector<vector<int>> dp(n, vector<int>(n+1, -1));
    //   //  vector<vector<int>>dp(n+1,vector<int>(a+1,-1));
    //     int p=solve(arr,0,diff,-1,dp);
    //     return p;
        // vector<int>dp(n,1);
        // int maxi=1;
        // for(int i=0;i<n;i++)
        // {
        //     for(int prev=0;prev<i;prev++)
        //     {
        //         if(arr[prev]+diff==arr[i])
        //         {
        //                 dp[i]=max(dp[i],1+dp[prev]);
        //         }
        //     }
        //     maxi=max(maxi,dp[i]);
        // }
        // return maxi;
         
        int res=1;

      //  int n=arr.size();

        unordered_map<int,int>dp;

        for(auto i:arr){
            int before_a=dp.count(i-difference)? dp[i-difference]:0;

            dp[i]=before_a+1;

            res=max(res,dp[i]);
        }

        return res;


    }
};