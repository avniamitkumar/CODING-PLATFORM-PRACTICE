//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxChildren(int n, int m, vector<int> &g, vector<int> &s) {
        // code here
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int c=0,i=0,j=0;
       while(i<n && j<m)
       {
           if(g[i]<=s[j])
           {
               i++;
              // j++;
               c++;
           }
           j++;
       }
       return c;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<int> greed(N), sz(M);
        for (int i = 0; i < N; i++) {
            cin >> greed[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> sz[i];
        }
        Solution obj;
        cout << obj.maxChildren(N, M, greed, sz) << endl;
    }
    return 0;
}
// } Driver Code Ends