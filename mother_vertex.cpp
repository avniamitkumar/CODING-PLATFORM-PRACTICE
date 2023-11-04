//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(vector<int>&vis,vector<int>adj[],int i)
    {
        vis[i]=1;
        for(auto it:adj[i])
        {
            if(!vis[it])
            {
                dfs(vis,adj,it);
            }
        }
    }
    
    
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	   
	   int ans=0;
	   vector<int>vis(V,0);
	   for(int i=0;i<V;i++)
	   {
	       if(!vis[i])
	       {
	           dfs(vis,adj,i);
	           ans=i;
	       }
	   }
	   vector<int>visi(V,0);
	   dfs(visi,adj,ans);
	   for(auto x:visi)
	   {
	       if(x==0)return -1;
	   }
	    return ans;
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
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends