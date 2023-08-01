//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
   void dfs(int node, stack<int>& st, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, st, adj, vis);
            }
        }
        st.push(node);
    }

    void revDfs(int node, vector<int>& vis, vector<vector<int>>& transpose) {
        vis[node] = 1;
        for (auto it : transpose[node]) {
            if (!vis[it]) {
                revDfs(it, vis, transpose);
            }
        }
    }

public:
    int kosaraju(int V, vector<vector<int>>& adj) {
        stack<int> st;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, st, adj, vis);
            }
        }

        // Step 2: Transpose
        vector<vector<int>> transpose(V);
        for (int i = 0; i < V; i++) {
            vis[i] = 0;
            for (auto it : adj[i]) {
                transpose[it].push_back(i);
            }
        }

        // Step 3: Process the stack
        int count = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (!vis[node]) {
                revDfs(node, vis, transpose);
                count++;
            }
        }

        return count;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends