//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int solve(int arr[],int ind,int target,vector<vector<int>>&dp)
    {
        if(target==0)
        {
            return 0;
        }
        // if(arr[ind]==target)return 1;
         if(ind == 0){
            if(target % arr[ind] == 0)
                return target/arr[ind];
            return -1e8;
        }
        if(dp[target][ind]!=-1)return dp[target][ind];
       // if(size==1 && arr[ind]%target==0) return arr[ind]/target;
        int notpick=solve(arr,ind-1,target,dp);
        int pick=-1e8;
        if(arr[ind]<=target)
        {
            pick=1+solve(arr,ind,target-arr[ind],dp);
        }
        return dp[target][ind]=max(pick,notpick);
        
        /*if(ind<0)
        {
            return 0;
        }
        if(arr[ind]==target)return 1;
        if(ind==3 && arr[ind]%target==0)arr[ind]%target==0
        
        int notpick=solve(arr,ind-1,target);
        int pick=INT_MIN;
        if(arr[ind]<=target)
        {
            pick=solve(arr,ind,target-arr[ind]);
        }
        return max(pick,notpick);*/
        
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        int arr[3]={x,y,z};
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        int ans=solve(arr,2,n,dp);
        if(ans>0)return ans;
        return 0;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends