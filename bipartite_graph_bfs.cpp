//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    bool chck(int V,vector<int>adj[],int st,int vis[])
    {
        queue<int>q;
	   // vector<int>vis(V,-1);
	    vis[st]=0;
	    q.push(st);
	    while(!q.empty())
	    {
	        int node=q.front();
	       // int col=q.front().second;
	        
	        q.pop();
	        
	        
	        
	        for(auto x:adj[node])
	        {
	            if(vis[x]==-1)
	            {
	                q.push(x);
	                vis[x]=!vis[node];
	            }
	            else
	            {
	                if(vis[x]==vis[node])
	                {
	                    return false;
	                }
	            }
	            
	        }
	        
	    }
	    
	    return true;
	    
    }
    
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int vis[V];
	    for(int i=0;i<V;i++)
	    {
	        vis[i]=-1;
	    }
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==-1)
	        {
	            if(chck(V,adj,i,vis)==false)return false;
	        }
	    }
	    
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends