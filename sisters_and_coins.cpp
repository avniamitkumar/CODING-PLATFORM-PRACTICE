//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends

int dp[5005][55];
class Solution{
public: 
    bool solve(int arr[],int ind,int n,int m,int s)
    {
        if(s==m)return 1;
        if(s<m)return 0;
        if(ind>=n)return 0;
       if(dp[m][ind]!=-1)return dp[m][ind];
        bool a=solve(arr,ind+1,n,m,s);
        bool b=solve(arr,ind+1,n,m+arr[ind],s-arr[ind]);
        return dp[m][ind]=a||b;
        
    }
    int sisterCoin(int arr[], int n, int m){
        // Code Here
        memset(dp,-1,sizeof(dp));
        int s=0;
        for(int i=0;i<n;i++)
        {
            s+=arr[i];
        }
        if((s+m)%2!=0)return 0;
        return solve(arr,0,n,m,s);
    }
};


//{ Driver Code Starts.

int main()
{
    Solution ob;
	int t;
	cin >> t;
	while(t--){
	    int n, m;
	    cin >> n >> m;
	    int a[n];
	    for(int i = 0; i < n; ++i){
	        cin >> a[i];
	    }
	    cout << ob.sisterCoin(a, n, m) << endl;
	    
	}
	return 0;
}
// } Driver Code Ends