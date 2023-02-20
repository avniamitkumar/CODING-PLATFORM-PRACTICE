//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	void immediateSmaller(vector<int>&arr, int n) {
	    //  code here
	    stack<int>st;
	    for(int i=0;i<n-1;i++)
	    {
	        if(arr[i+1]<arr[i])
	        {
	            st.push(arr[i+1]);
	        }
	        else
	        {
	            st.push(-1);
	        }
	    }
	    st.push(-1);
	    int j=n-1;
	    while(!st.empty())
	    {
	        arr[j]=st.top();
	        st.pop();
	        j--;
	    }
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.immediateSmaller(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends