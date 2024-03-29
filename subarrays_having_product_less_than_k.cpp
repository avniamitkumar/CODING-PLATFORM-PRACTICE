//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& arr, int n, long long k) {
        if (k <= 1) return 0;
        int i=0;
        int j=0;
        long prod=1;
        int no=0;
        while(j<n)
        {
            prod*=arr[j];
             while(prod>=k){
                prod/=arr[i];
                    i++;
                }
               no+=j-i+1;
            
          
            j++;
        }
        return no;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends