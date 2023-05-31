//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> end) {
        // code here
         int n=grid.size(), m=grid[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        int sr=source.first;
        int sc=source.second;
        int er=end.first;
        int ec=end.second;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        dis[sr][sc]=0;
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        pq.push({0,{sr,sc}});
        while(!pq.empty())
        {
            int d=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int nr=r+delrow[i];
                int nc=c+delcol[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]!=0 && dis[nr][nc]>d+1)
                {
                    dis[nr][nc]=d+1;
                    pq.push({dis[nr][nc],{nr,nc}});
                }
                
            }
            
            
        }
        
        if(dis[er][ec]!=1e9)return dis[er][ec];
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends