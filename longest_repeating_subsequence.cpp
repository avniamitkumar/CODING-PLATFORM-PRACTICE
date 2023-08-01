//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int solve(int i,int j,string&str,string&txt,vector<vector<int>>&dp)
	    {
	        if(i<0 || j<0)return 0;
	        if(dp[i][j]!=-1)return dp[i][j];
	        if(str[i]==txt[j] && i!=j)
	        {
	            return dp[i][j]=1+solve(i-1,j-1,str,txt,dp);
	        }
	        return dp[i][j]=max(solve(i-1,j,str,txt,dp),solve(i,j-1,str,txt,dp));
	    }
	
	
	
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n=str.size();
		    string txt(str.begin(),str.end());
		    vector<vector<int>>dp(n+1,vector<int>(n+1,9));
		    
		    for(int i=0;i<=n;i++)
		    {
		        for(int j=0;j<=n;j++)
		        {
		              if(i==0 || j==0){
                    dp[i][j]=0;
                }
		            else if(str[i-1]==txt[j-1] && i!=j)
            	        {
            	             dp[i][j]=1+dp[i-1][j-1];//solve(i-1,j-1,str,txt,dp);
            	        }else{
            	 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);//max(solve(i-1,j,str,txt,dp),solve(i,j-1,str,txt,dp));
}		        }
		    }
		    return dp[n][n];
		    
		   // return solve(n-1,n-1,str,txt,dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends