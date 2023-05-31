//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
                  vector<pair<int,int>> adj[n];
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
         int cityno,mincitycount=1e9;

        for(int i=0;i<n;i++)
        {
            vector<int>dist(n,INT_MAX);
              priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
              pq.push({0,i});
              dist[i]=0;
              
              while(!pq.empty())
              {
                  int d=pq.top().first;
                  int node=pq.top().second;
                  pq.pop();
                  for(auto it:adj[node])
                  {
                      int adjNode=it.first;
                    int adjWeight=it.second;
                      if(d + adjWeight < dist[adjNode])
                    {
                        dist[adjNode] = d + adjWeight;
                        pq.push({dist[adjNode],adjNode});
                    }
                  }
              }
             int count=0;
            for(int j=0;j<n;j++)
            {
                if(dist[j]<=distanceThreshold)
                    count++;
            }
            if(count<=mincitycount)
            {
                mincitycount=count;
                cityno = i;
            }
        }
                
                
               return cityno;  }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends