//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	//KAHN'S ALGORITHM
	/*	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    queue<int>q;
	    int indegree[V]={0};
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    vector<int>topo;
	    while(!q.empty())
	    {
	        topo.push_bacl(q.front());
	        iny node=q.front();
	        q.pop();
	        for( auto it:adj[node])
	        {
	            indegree[it]--
	            if(indegree[it]==0)
	            {
	                q.push(it);
	            }
	        }
	        return topo;
	    }
	    
	}
	*/
	
	
	void dfs(int node,int V,vector<int>adj[],int vis[],stack<int> &st)
	{
	    vis[node]=1;
	    for(auto x:adj[node])
	    {
	        if(!vis[x])
	        {
	            dfs(x,V,adj,vis,st);
	        }
	    }
	    st.push(node);
	}
	
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int vis[V]={0};
	    stack<int>st;
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            dfs(i,V,adj,vis,st);
	        }
	    }
	    vector<int>ans;
	    while(!st.empty())
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	    
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends