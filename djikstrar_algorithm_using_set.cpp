//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        //  USING PRIORITY QUEUE
        /*priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>dis(V);
      for(int i=0;i<V;i++)dis[i]=1e9;
      pq.push({0,S});
        dis[S]=0;
        while(!pq.empty())
        {
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            for(auto x:adj[node])
            {
                int edgw=x[1];
                int adjn=x[0];
                if(dis[adjn]>d+edgw)
                {
                    dis[adjn]=d+edgw;
                    pq.push({dis[adjn],adjn});
                }
                
            }
            
            
        }
        return dis;
        */
        
        set<pair<int,int>>st;
        vector<int>dis(V,1e9);
        
        st.insert({0,S});
        dis[S]={0};
        
        while(!st.empty())
        {
            auto it=*(st.begin());
            int node=it.second;
            int d=it.first;
            st.erase(it);
            for(auto it:adj[node])
            {
                int edw=it[1];
                int adjn=it[0];
                
                if(d+edw<dis[adjn])
                {
                    if(dis[adjn]!=1e9)
                    {
                        st.erase({dis[adjn],adjn});
                        
                    }
                    
                    dis[adjn]=d+edw;
                    st.insert({dis[adjn],adjn});
                }
            
            
                
                
            }
            
        }
        
        return dis;
        
        
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends