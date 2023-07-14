//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	
	
	
	
	int LongestBitonicSequence(vector<int>arr)
	{
	    // code here
	    int n=arr.size();
	    vector<int>dp1(n,1);
	    vector<int>dp2(n,1);
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int prev=0;prev<i;prev++)
	        {
	            if(arr[i]>arr[prev] && dp1[i]<1+dp1[prev])
	            {
	                dp1[i]=1+dp1[prev];
	            }
	        }
	    }
	    
	    for(int j=n-1;j>=0;j--)
	    {
	        for(int next=n-1;next>j;next--)
	        {
	            if(arr[j]>arr[next] && dp2[j]<1+dp2[next])
	            {
	                dp2[j]=1+dp2[next];
	            }
	        }
	    }
	    int ans=0;
	    for(int i=0;i<n;i++)
	    {
	        ans=max(ans,dp1[i]+dp2[i]);
	    }
	    return ans-1;
	    
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends