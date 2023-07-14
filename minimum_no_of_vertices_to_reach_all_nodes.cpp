class Solution {
public:
    void dfs(int i,vector<int>adj[],vector<int>&vis)
    {
        vis[i]=1;
        for(auto it:adj[i])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis);
            }
        }

    }



    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
         for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
        }
        vector<int>ans;
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++)
        {
              for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        vector<int>topo;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        vector<int>vis(n,0);
     //   vector<int>res;
        for(auto ele: topo){
            if(!vis[ele]){
                vis[ele]=true;
                ans.push_back(ele);
                dfs(ele,adj,vis);
            }
        }


        return ans;
    }
};