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
        else if(rank[p_x]<rank[p_y])
         {
            parent[p_x]=p_y;
        }
        else
        {
             
            parent[p_x]=p_y;
            rank[p_y]++;
        }

    }


    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
         vector<pair<int, pair<int, int>>> adj;
        
        // generating graph basically with weights
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int weight = abs(points[i][0] - points[j][0]) + 
                             abs(points[i][1] - points[j][1]);//manhattan distance
                
                adj.push_back({weight, {i, j}});
                
            }
        }
        
        // sort on the basis of their edge weight
        sort(adj.begin(), adj.end());
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){parent[i]=i;}
       // vector<vector<int>>edges
       int sum=0;
       for(int i=0;i<adj.size();i++)
       {
           int a=find(adj[i].second.first);
           int b=find(adj[i].second.second);
           if(a!=b)
           {
               Union(a,b);
               sum+=adj[i].first;
           }
       }
return sum;
    }
};