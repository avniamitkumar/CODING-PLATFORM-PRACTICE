//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define mod 1000000007
class Solution{

	public:
	void ss(int arr[],int n,int sum,int i,int s,vector<int>&ds,int &cnt)
	{
	    if(i>=n)
	    {
	        if(s==sum)
	        {
	         cnt++;   
	        }
	        return;
	    }
	    ds.push_back(arr[i]);
	    s+=arr[i];
	    ss(arr,n,sum,i+1,s,ds,cnt);
	    s-=arr[i];
	    ds.pop_back();
	    ss(arr,n,sum,i+1,s,ds,cnt);

	    
	}
	
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector <int>ds;
        int c=0;
        ss(arr,n,sum,0,0,ds,c);
        return c%mod;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends