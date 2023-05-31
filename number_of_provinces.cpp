//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int vis[500] = {0};
   void bfsOfGraph(int V, vector<vector<int>> adj,int st) {
        // Code here
       //int vis[V]={0};;
        queue<int>q;
        vis[st]=1;
        q.push(st);
        //vector<int>bfs;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            //bfs.push_back(node);
            for (int i = 0; i < V; i++) {
                if (adj[node][i] && !vis[i]) {
                    q.push(i);
                    vis[i] = 1;
                }}
            
        }
        //return bfs;
    }
    int numProvinces(vector<vector<int>> adj, int V) {
       // vector<int>vis(V+1,0);
        int cnt=0;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
               // cnt++;
                bfsOfGraph(V,adj,i);
                cnt++;
            }
            
        }
        return cnt;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends