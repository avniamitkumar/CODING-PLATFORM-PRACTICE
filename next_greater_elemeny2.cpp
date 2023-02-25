//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nextGreaterElement(int n, vector<int>& arr) {
        // code here
        stack<int>st;
        vector<int>ans;
       for(int i=2*n-1;i>=0;i--)
       {
           while(!st.empty() && st.top()<=arr[i%n])
           {
               st.pop();
           }
           if(i<n)
           {
               if(!st.empty())
               {
                   ans.push_back(st.top());
               }
               else
               {
                   ans.push_back(-1);
               }
           }
           st.push(arr[i%n]);
       }
       reverse(ans.begin(),ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends