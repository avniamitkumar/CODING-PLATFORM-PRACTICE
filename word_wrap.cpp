//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
int dp[500][2000];

class Solution {
public:
    int solve(vector<int>&nums,int k,int ind,int rem)
    {
        if(ind>=nums.size())
        {
            return 0;
        }
       if(dp[ind][rem]!=-1)
        {
            return dp[ind][rem];
        }
        int ans;

        if(nums[ind]>rem)
        {
            ans=(rem+1)*(rem+1)+solve(nums,k,ind+1,k-nums[ind]-1);
        }
        else
        {
            int present=solve(nums,k,ind+1,rem-nums[ind]-1);
            int next=(rem+1)*(rem+1)+solve(nums,k,ind+1,k-nums[ind]-1);
            ans=min(present,next);
        }
        dp[ind][rem]=ans;
        return  dp[ind][rem];
        
    }



    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        memset(dp, -1, sizeof(dp));
        return solve( nums,k, 0, k);
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends