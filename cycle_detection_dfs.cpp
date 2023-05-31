//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public://BFS
    bool detect(int src,vector<int>adj[],int vis[])
    {
        vis[src]=1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        while(!q.empty())
        {
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto x:adj[node])
            {
                if(!vis[x])
                {
                    vis[x]=1;
                    q.push({x,node});
                    
                }
                else if(parent!=x)
                {
                    return true;
                    
                }
            }
        }
        return false;
    }
  //DFS
/*    void dfs(int i,vector<int> adj[],vector<int>&vis,vector<int>&par,int &f){
        vis[i]=1;
        for(auto &x:adj[i]){
            if(!vis[x]){
                par[x]=i;
                dfs(x,adj,vis,par,f);
            }
            else{
                if(par[i]==x)
                continue;
                else 
                {f=1;
                break;}
            }
        }
    }
     bool isCycle(int v, vector<int> adj[]) {
        vector<int>vis(v,0);
        vector<int>par(v,-1);
        int f=0;
        for(int i=0;i<v;++i){
            if(!adj[i].empty() and !vis[i]){
                dfs(i,adj,vis,par,f);
                if(f)
                return true;
            }
        }
        return false;
    }
};*/
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int
        vis[V]={0};
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(detect(i,adj,vis))return true;   
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends