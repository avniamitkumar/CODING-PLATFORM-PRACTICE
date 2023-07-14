//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int helper(int i, vector<int>nums, int k, int n, vector<int>& dp)
{
    // Base case: If we have reached the end of the array,
    // return 0
    if (i == n)
        return 0;

    // Initialize the length of the current subarray to 0
    int len = 0;

    // Initialize the maximum element in the current
    // subarray to the minimum integer value
    int mx = INT_MIN;

    // Initialize the maximum possible score that can be
    // achieved to the minimum integer value
    int ans = INT_MIN;

    // If we have already computed the value of dp[i],
    // return it
    if (dp[i] != -1)
        return dp[i];

    // Loop through all possible subarrays of size k or less
    // starting from the current index i
    for (int j = i; j < min(n, i + k); j++) {

        // Increment the length of the current subarray
        len++;

        // Update the maximum element in the current
        // subarray
        mx = max(mx, nums[j]);

        // Calculate the sum of the maximum element in the
        // current subarray multiplied by the length of the
        // subarray and the maximum possible score that can
        // be achieved after partitioning the remaining part
        // of the array
        int sum = len * mx + helper(j + 1, nums, k, n, dp);

        // Update the maximum possible score if the current
        // sum is greater than the current maximum
        ans = max(ans, sum);
    }

    // Store the maximum possible score that can be achieved
    // after partitioning the remaining part of the array
    // starting from the current index i in the dp array
    dp[i] = ans;

    // Return the maximum possible score that can be
    // achieved after partitioning the remaining part of the
    // array starting from the current index i
    return ans;
}

int solve( int n, int k,vector<int>nums)
{
    // Create a dp array of size n, initialized to -1
    vector<int> dp(n, -1);

    // Call the helper function with the starting index 0,
    // the array nums, the maximum subarray size k, the
    // length of the array n, and the dp array Return the
    // maximum possible score that can be achieved after
    // partitioning the array
    return helper(0, nums, k, n, dp);
}
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.solve(n,k,arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends