//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:
	int findMaxSubarraySum(long long arr[], int n, long long k)
	{
	    // Your code goes here
	    int i=0;
	    int j=0;
	    int maxi=0;
	    int sum=0;
	    int si=0;
	    int sj=0;
	    while(j<n)
	    {
	        sum+=arr[j];
	         while(sum>k)
	            {
	                sum-=arr[i];
	                i++;
	            }
	        if(sum<=k)
	        {
	            //j++;
	            maxi=max(maxi,sum);
	            
	        }
	        j++;
	    }
	    return maxi;
	}  

};
	  



//{ Driver Code Starts.

int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	 int n;
        cin>>n;
        
        long long a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        
        long long sum;
        cin >> sum;
        

        Solution ob;
		cout << ob.findMaxSubarraySum(a, n, sum);
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends