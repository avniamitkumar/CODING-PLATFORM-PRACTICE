//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int n) {
        // Code here
        //sort(arr,arr+N);
        sort(arr.begin(), arr.end());
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            
            if(arr[i]<=arr[i-1])
            {
                int val=arr[i-1]-arr[i]+1;
                cnt+=val;
                arr[i]+=val;
            }
        }
        return cnt;
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
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends