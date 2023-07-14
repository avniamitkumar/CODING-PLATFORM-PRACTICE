class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x)
    {
        if(x==parent[x])
        {
            return x;
        }
        return parent[x]=find(parent[x]);
    }

     void Union(int x,int y)
    {
        int p_x=find(x);
        int p_y=find(y);
        if(rank[p_x]>rank[p_y])
        {
            parent[p_y]=p_x;
        }
        else if(rank[p_y]>rank[p_x])
        {
            parent[p_x]=p_y;
        }
        else
        {
            parent[p_x]=p_y;
            rank[p_y]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int m=edges.size();
        parent.resize(m+1);
        rank.resize(m+1);
        for(int i=0;i<=m;i++)
        {
            parent[i]=i;
        }
        for(auto &e:edges)
        {
            int u=e[0];
            int v=e[1];
            if(find(u)==find(v))
            {
                return {u,v};
            }
            Union(u,v);
            
        }

        return {-1,-1};
    }
};