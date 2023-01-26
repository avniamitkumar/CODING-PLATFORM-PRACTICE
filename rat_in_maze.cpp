//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(vector<vector<int>> &m,vector<string>&ans,string path,int row,int col,int n)
    {
        if(row==n-1 && col==n-1 && m[row][col]==1 )
        {
            ans.push_back(path);
            return;
        }
        if(row<0 || col<0 || row>=n || col>=n || m[row][col]==0 || m[row][col]==-1)
        {
            return;
        }
        int p=m[row][col];
        if(m[row][col]==1){
        m[row][col]=-1;
    
        solve(m,ans,path+'D',row+1,col,n);
        solve(m,ans,path+'U',row-1,col,n);
        solve(m,ans,path+'L',row,col-1,n);
        solve(m,ans,path+'R',row,col+1,n);
        m[row][col]=p;}
        
    }
    
    
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        string temp;
        solve(m,ans,temp,0,0,n);
        return ans;
        
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends