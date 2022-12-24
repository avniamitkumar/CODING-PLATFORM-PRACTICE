//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int f=-1,l=-1;
	    int st=0,end=n-1;
	    while(st<=end)
	    {
	        int mid= st + (end-st)/2;
	        if(arr[mid]==x)
	        {
	            f=mid;
	            end=mid-1;
	        }
	        else if(arr[mid]>x)
	        {
	            end=mid-1;
	        }
	        else
	        {
	            st=mid+1;
	        }
	    }
	    st=0,end=n-1;
	    while(st<=end)
	    {
	        int mid= st + (end-st)/2;
	        if(arr[mid]==x)
	        {
	            l=mid;
	            st=mid+1;
	        }
	        else if(arr[mid]>x)
	        {
	            end=mid-1;
	        }
	        else
	        {
	            st=mid+1;
	        }
	    }
	    if(f==-1)
	    {
	        return 0;
	    }
	    else
	    {
	        int cnt=l-f+1;
	        return cnt;
	    }
	    
	    
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends