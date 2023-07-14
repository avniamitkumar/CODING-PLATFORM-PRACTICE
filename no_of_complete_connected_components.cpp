class Solution {
public:
    void dfs(int i,vector<int>adj[],vector<int>&vis,vector<int>&nodes)
    {
        vis[i]=1;
        nodes.push_back(i);
        for(int it:adj[i])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis,nodes);
            }
        }
    }



    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto r:edges)
        {
            adj[r[0]].push_back(r[1]);
            adj[r[1]].push_back(r[0]);
        }
        vector<int>vis(n,0);
        int ans=0;

        for(int i=0;i<n;i++)
        {
                if(!vis[i])
                {
                    vector<int>nodes;
                    dfs(i,adj,vis,nodes);
                
                int f=1;
                for(int i:nodes)
                {
                    unordered_set<int>s(adj[i].begin(),adj[i].end());
                    for(int j:nodes)
                    {
                        if(i==j)continue;
                        if(s.find(j)==s.end())
                        {
                            f=0;

                            break;
                        }
                    }
                }
                  ans+=f;}
        }
    return ans;
    }

};