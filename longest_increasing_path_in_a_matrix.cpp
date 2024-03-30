//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isvalid(vector<vector<int>>& matrix, int n, int m, int i, int j, int a, int b) {
        
        if(i<0 or j<0 or i>=n or j>=m) {
            return false;
        }
        if(matrix[i][j]<=matrix[a][b]) {
            return false;
        }
        return true;
    }
    int maxpath(vector<vector<int>>& dis, vector<vector<int>>& vis, vector<vector<int>>& matrix, int n, int m, int i, int j) {
        
        if(dis[i][j]>=1 and vis[i][j]==true) {
            return dis[i][j];
        }
        
        vis[i][j]=true;
        int a,b,c,d;
        if(isvalid(matrix,n,m,i+1,j,i,j)) {
            a=maxpath(dis,vis,matrix,n,m,i+1,j);
        }
        else a=0;
        
        if(isvalid(matrix,n,m,i,j+1,i,j)) {
            b=maxpath(dis,vis,matrix,n,m,i,j+1);
        }
        else b=0;
        
        if(isvalid(matrix,n,m,i-1,j,i,j)) {
            c=maxpath(dis,vis,matrix,n,m,i-1,j);
        }
        else c=0;
        
        if(isvalid(matrix,n,m,i,j-1,i,j)) {
            d=maxpath(dis,vis,matrix,n,m,i,j-1);
        }
        else d=0;
        
        return dis[i][j]=1+max({a,b,c,d});
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix, int n, int m) {

        // Code here
        vector<vector<int>> dis(n,vector<int>(m,1));
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(!vis[i][j]) {
                    maxpath(dis,vis,matrix,n,m,i,j);
                }
            }
        }
        int ans=1;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                ans=max(ans,dis[i][j]);
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.longestIncreasingPath(matrix, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends