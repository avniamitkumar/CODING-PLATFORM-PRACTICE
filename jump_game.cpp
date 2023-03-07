//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int canReach(int arr[], int n) {
        // code here
        if(arr[0]==0 && n==1)
        {
            return 1;
        }
        int st=arr[0];
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0 && st<=i)
            {
                return 0;
            }
            if(i+arr[i]>st)
            {
                st=i+arr[i];
            }
            if(st>=n-1)
            {
                return 1;
            }
           
        }
         return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends