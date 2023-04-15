//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    	int solve(int arr[],int ind,vector<int>&dp)
	{
	    if(ind<0)
	    {
	        return 0;
	    }
	    if(ind==0)
	    {
	        return arr[0];
	    }
	     if(dp[ind]!=-1){

        return dp[ind];

    }   
	    int a=solve(arr,ind-2,dp)+arr[ind];
	    int b=solve(arr,ind-1,dp)+0;
	    return    dp[ind]=max(a,b);
	    
	}
	//TABULATION
	/*
	int FindMaxSum(int arr[], int n){
        int dp[n];
        dp[0] = arr[0];
        
        for(int i=1;i<n;i++){
            int pick = arr[i];
            if(i > 1) pick += dp[i-2];
            
            int notPick = dp[i-1];
            dp[i] = max(pick, notPick);
        }
        return dp[n-1];
    }
	
	*/
	
	//SPACE OPTIMISATION
	/*
	int FindMaxSum(int arr[], int n){
        int prev2 = 0;
        int prev = arr[0];
        
        for(int i=1;i<n;i++){
            int pick = arr[i];
            if(i > 1) pick += prev2;
            
            int notPick = prev;
            int curr = max(pick, notPick);
            
            prev2 = prev;
            prev = curr;
        }
        return prev;
	
	*/
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int>dp(n,-1);
	    return solve(arr,n-1,dp);
	    //return sum;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends