//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	   unordered_map<int,int>mp;
       int mx=0;
       int sum=0;
       for(int i=0;i<n;i++)
       {
           sum+=arr[i];
            int rem = sum % k;
	        rem = (rem + k) % k;
           if(sum%k==0)
           {
               mx=i+1;
           }
           else
           {
               if(mp.find(rem)!=mp.end())
               {
                   mx=max(mx,i-mp[rem]);
               }
               
           }
           if(mp.find(rem)==mp.end())
           {
               mp[rem]=i;
           }
       }
       return mx;
	    
	    
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends