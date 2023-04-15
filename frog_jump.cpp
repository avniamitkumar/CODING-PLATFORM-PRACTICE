//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  //recursion
    int Rec(int n, vector<int> &height){
        if(n == 0){
            return 0;
        }
        int left = Rec(n-1, height) + abs(height[n] - height[n-1]);
        int right = INT_MAX;
        if(n > 1){
            right = Rec(n-2, height) + abs(height[n] - height[n-2]);
        }
        return min(left, right);
    }

//memorization
    int Memo(int n, vector<int>& height, vector<int>& dp)
    {
        // step 1 : create the array of vector of size n+1;
        
        if(n == 0)
        {
            return 0;
        }
        
        // check allready store 
        if(dp[n] != -1)
        {
            return dp[n];
        }

//tabulation
        
        int left = Memo(n-1, height, dp) + abs(height[n] - height[n-1]);
        int right = INT_MAX;
        
        if(n > 1)
        {
            right = Memo(n-2, height, dp) + abs(height[n] - height[n-2]);
        }
        
        // store it into the dp vector and then return;
        return dp[n] = min(left, right);
        
    }
    int tab(int n, vector<int> &height){
       // step 1 : create the array of vector of size n+1
        //vector<int>dp(n+1, -1);
        vector<int>dp(n, 0);
        
        dp[0] = 0;
        
        
        for(int i= 1; i<n; i++)
        {
            int left = dp[i-1] + abs(height[i] - height[i-1]);
            
            int right = INT_MAX;
            // if the index is greater than one then only run
            if(i > 1)
            {
                right = dp[i-2] + abs(height[i] - height[i-2]);
            }
            
            dp[i] = min(left, right);
        }
        
        return dp[n-1];
    }

//space optimaization


    int spac(int n, vector<int> &height){
        int prev2=0;
        int prev1=0;
        
        for(int i= 1; i<n; i++)
        {
            int left = prev1 + abs(height[i] - height[i-1]);
            
            int right = INT_MAX;
            // if the index is greater than one then only run
            if(i > 1)
            {
                right = prev2 + abs(height[i] - height[i-2]);
            }
            
            int curri = min(left, right);
            
            // alternate
            prev2 = prev1;
            prev1 = curri;
        }
        
        return prev1;
    }
    
    
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n+1, 0);
        // return Rec(n-1, height);
        // return Memo(n, height, dp);
        return tab(n, height);
        return spac(n, height);
    }

};

0

kartiksarvaiya42



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
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends