//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        // code here
        priority_queue<int,vector<int>,greater<int>> pq;
        vector<int>my;
        for(int i=0;i<n;i++)
        {
             pq.push(arr[i]);
            if(pq.size()<k)
            {
                my.push_back(-1);
            }
            if(pq.size()==k)
            {
                my.push_back(pq.top());
            }
            else if(pq.size()>k)
            {
                  pq.pop();
                my.push_back(pq.top());
            }
            
        }
        return my;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends