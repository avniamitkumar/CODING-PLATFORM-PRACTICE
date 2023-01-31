//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int num, int i) {

        i--;

        long long n=num;

        long long one=1;

        long long get=n & (one << i);

        long long set=n | (one << i);

        long long clear=n & (~(one << i));

        cout << (get != 0) << ' ' << set << ' ' << clear;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends