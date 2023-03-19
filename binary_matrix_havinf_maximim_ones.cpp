//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        //code here
    int maxRow = 0;
    int maxCount = 0;
    int j = N - 1;
    for (int i = 0; i < N; i++) {
        // If the current row has fewer 1s than the maximum we've seen so far, skip it
        if (N - j - 1 < maxCount) {
            break;
        }
        // Move left until we find the first 1 in the row
        while (j >= 0 && mat[i][j] == 1) {
            j--;
        }
        // If the current row has more 1s than the maximum we've seen so far, update maxRow and maxCount 
        if (N - j - 1 > maxCount) {
            maxRow = i;
            maxCount = N - j - 1;
        }
    }
    
    return {maxRow, maxCount};
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends