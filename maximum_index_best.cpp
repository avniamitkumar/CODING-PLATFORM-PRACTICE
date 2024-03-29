//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
       vector<int> left_min(n,INT_MAX);
        vector<int> right_max(n,INT_MIN);
        int ans = 0;
        left_min[0] = arr[0];
        right_max[n-1] = arr[n-1];
        for(int i=1;i<n;++i){
            left_min[i] = min(arr[i],left_min[i-1]);
        }
        for(int i = n-2;i>=0;--i){
            right_max[i] = max(arr[i],right_max[i+1]);
        }
        // for(auto i:left_min) cout<<i<<" ";
        // cout<<endl;
        // for(auto i:right_max) cout<<i<<" ";
        // cout<<endl;
        
        int lptr = 0, rptr = 0;
        while(lptr < n && rptr < n){
            if(left_min[lptr] <= right_max[rptr]){
                // cout<<lptr<<" "<<rptr<<endl;
                ans = max(ans, rptr-lptr);
                ++rptr;
            }else{
                ++lptr;
            }
        }
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends