//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    //USING DFS
    bool dfs(vector<int>adj[],int i,vector<int>&vis,vector<int>&rec)
    {
        vis[i]=1;
        rec[i]=1;
        for(auto it:adj[i])
        {
            if(!vis[it])
            {
                if(dfs(adj,it,vis,rec))return true;
            }
            else if(vis[it]==1 && rec[it]==1)
            {
                return true;
            }
        }
        rec[i]=0;
        return false;
    }
    
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0);
        vector<int>rec(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(adj,i,vis,rec))return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends