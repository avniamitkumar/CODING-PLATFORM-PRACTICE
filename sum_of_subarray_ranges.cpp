//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    long long subarrayRanges(int n, vector<int> &arr) {
        // code here
        //NSE
        stack<int> st;
        vector<int>nse(n,n);
        for(int i=n-1;i>=0;i--)
        {
            while (!st.empty() and arr[st.top()] > arr[i])
                st.pop();

            if (!st.empty())
                nse[i] = st.top();

            st.push(i);       
        }
         while (!st.empty())
            st.pop();
        //PSE
        vector<int>pse(n,-1);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and arr[st.top()]>= arr[i])
                st.pop();

            if (!st.empty())
                pse[i] = st.top();

            st.push(i);
        }
        while (!st.empty())
            st.pop();
        //nge
        vector<int>nge(n,n);
        for(int i=n-1;i>=0;i--)
        {
            while (!st.empty() and arr[st.top()]< arr[i])
                st.pop();

            if (!st.empty())
                nge[i] = st.top();

            st.push(i);       
        }
         while (!st.empty())
            st.pop();
        //pge
        vector<int>pge(n,-1);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and arr[st.top()]<= arr[i])
                st.pop();

            if (!st.empty())
                pge[i] = st.top();

            st.push(i);
        }
        long long res=0;
        for(int i=0;i<n;i++){
            long long MAX=arr[i]*(i-pge[i])*(nge[i]-i); // contribution of arr[i] as minimum element
            long long MIN=arr[i]*(i-pse[i])*(nse[i]-i);  //  contribution of arr[i] as maximum element
            res+=(MAX-MIN);  // contribution to final answer
        }
        return res;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayRanges(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends