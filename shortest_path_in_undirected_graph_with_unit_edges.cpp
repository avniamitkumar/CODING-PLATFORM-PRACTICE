//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int>adj[N];
        for( auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<pair<int,int>>q;
        q.push({src,0});
        int dist[N];
       
        for(int i=0;i<N;i++)
        {
            dist[i]=INT_MAX;
        }
         dist[src]=0;
        while(!q.empty())
        {
            int node=q.front().first;
            int d=q.front().second;
            q.pop();
            for(auto x:adj[node])
            {
                if(d+1<dist[x])
                {
                    dist[x]=d+1;
                    q.push({x,dist[x]});
                }
            }
            
        }
        
         vector<int> ans(N,-1);
        
        for(int i=0;i<N;i++){
           if(dist[i]!= INT_MAX){
              ans[i]=dist[i];
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends