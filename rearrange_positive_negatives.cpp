//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    int posi[n],negi[n];
	    int k=0,j=0;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]>=0)
	        {
	            posi[k]=arr[i];
	            k++;
	        }
	        else
	        {
	            negi[j]=arr[i];
	            j++;
	        }
	    }
	    int l=0,m=0,p=0;
	    while(l<k && m<j)
	    {
	        if(p%2==0)
	        {
	            arr[p++]=posi[l++];
	        }
	        else
	        {
	            arr[p++]=negi[m++];
	        }
	    }
	    while(l<k)
	    {
	        arr[p++]=posi[l++];
	    }
	    while(m<j)
	    {
	        arr[p++]=negi[m++];
	    }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends