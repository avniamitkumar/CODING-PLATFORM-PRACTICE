//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int sumSubarrayMins(int n,vector<int>& arr) {
        //int n = arr.size(), 
        int mod = 1e9 + 7;

        stack<pair<int, int>> st;
        vector<int> pse(n, -1);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and st.top().first > arr[i])
                st.pop();

            if (!st.empty())
                pse[i] = st.top().second;

            st.push({arr[i], i});
        }

        while (!st.empty())
            st.pop();

        vector<int> nse(n, n);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() and st.top().first >= arr[i])
                st.pop();

            if (!st.empty())
                nse[i] = st.top().second;

            st.push({arr[i], i});
        }

        long ans = 0;
        for (int i = 0; i < n; i++)
        {
            long left = i - pse[i];
            long right = nse[i] - i;
            ans = (ans + left * right * arr[i]) % mod;
        }

        return ans;
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
        cout << obj.sumSubarrayMins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends