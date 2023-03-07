//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minStep(int h, int u, int d){
        // code here
        int k=h-d;
        int step;
        step=(k)/(u-d);
        return step+1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        int H, U, D;
        cin >> H >> U >> D;
        
        Solution ob;
        cout<<ob.minStep(H, U, D)<<"\n";
    }
    return 0;
}
// } Driver Code Ends