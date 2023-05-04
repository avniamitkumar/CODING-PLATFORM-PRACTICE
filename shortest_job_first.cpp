//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// Back-end complete function Template for C++

class Solution {
  public:
    int solve(vector<int>& bt) {
        // code here
        int n=bt.size();
        
        sort(bt.begin(),bt.end());
        vector<int>wt(n,0);
        wt.push_back(0);
        for(int i=1;i<n;i++)
        {
            wt[i]=bt[i-1]+wt[i-1];
            //cout<<bt[i-1]<<" + "<<wt[i-1]<<"== "<<wt[i]<<endl;
            
        }
        int sum=0;
        for(int i=0;i<wt.size();i++)
        {
            sum+=wt[i];
        }
        return (int)(sum/bt.size());
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> bt(n), p(n);
        for (int i = 0; i < n; i++) {
            cin >> bt[i];
        }
        Solution obj;
        int ans = obj.solve(bt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends