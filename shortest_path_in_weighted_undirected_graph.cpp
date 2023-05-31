//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    vector<pair<int,int>> dis(n+1);
    for(int i = 0; i <= n; i++) {
        dis[i].first = 1e9;
    }

    vector<vector<pair<int, int>>> adj(n+1);
    for(int i = 0; i < edges.size(); i++) {
        int a = edges[i][0];
        int b = edges[i][1];
        int weight = edges[i][2];
        adj[a].push_back({b, weight});
        adj[b].push_back({a, weight});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1}); // distance, vertex
    dis[1].first = 0;
    dis[1].second = -1;

    while(!pq.empty()) {
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        for(auto x : adj[node]) {
            int adjn = x.first;
            int edgw = x.second;
            if(d + edgw < dis[adjn].first) {
                dis[adjn].first = d + edgw;
                dis[adjn].second = node;
                pq.push({dis[adjn].first, adjn});
            }
        }
    }

    if(dis[n].first == 1e9) {
        return {-1};
    }

    vector<int> ans;
    int curr = n;
    while(curr != -1) {
        ans.push_back(curr);
        curr = dis[curr].second;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends