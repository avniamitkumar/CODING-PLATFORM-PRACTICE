class Solution {
public:
    int N;
    class UnionFind
    {
        public:
        vector<int>rank;
        vector<int>parent;

        UnionFind(int n)
        {
            parent.resize(n);
            rank.resize(n, 0);
            for(int i=0;i<n;i++)
            {
                parent[i]=i;
            }
        }
        int find(int x)
        {
            if(x==parent[x])
            {
                return x;
            }
            return parent[x]=find(parent[x]);
        }

        bool Union(int x,int y)
        {
            int p_x=find(x);
            int p_y=find(y);


            if (p_x == p_y) 
            {    return false;}

            if(rank[p_x]>rank[p_y])
            {
                parent[p_y]=p_x;
               // rank[p_x]++;
            }
            else if(rank[p_y]>rank[p_x])
            {
                parent[p_x]=p_y;
               // rank[p_y]++;
            }
            else
            {
                 parent[p_x] = p_y;
                rank[p_y]++;
            }
            return true;
        }

    };

    int Kruskal(vector<vector<int>>&vec,int skip_edge,int force_edge)
    {
        int sum=0;
        UnionFind uf(N);

        if(force_edge!=-1)
        {
            uf.Union(vec[force_edge][0], vec[force_edge][1]);
            sum += vec[force_edge][2];
        }

        for(int i=0;i<vec.size();i++)
        {
            if(i==skip_edge)
            {
                continue;
            }
            int u=vec[i][0];
            int v=vec[i][1];
            int wt=vec[i][2];

            int p_u=uf.find(u);
            int p_v=uf.find(v);

            if(p_u!=p_v)
            {
                uf.Union(u,v);
                sum+=wt;
            }
        }
         for(int i = 0; i < N; i++) {
            if(uf.find(i) != uf.find(0))
                return INT_MAX;
        }
        
        return sum;

    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        N=n;
        for(int i=0;i<edges.size();i++)
        {
            edges[i].push_back(i);
        }
        auto comparator = [&](auto &v1, auto &v2) {
            return v1[2] < v2[2];
        };
        sort(edges.begin(), edges.end(), comparator);
        int MST_WEIGHT = Kruskal(edges, -1, -1);
        vector<int> critical, pseudo_critical;
        for(int i = 0; i < edges.size(); i++) {
          
            if(Kruskal(edges, i, -1) > MST_WEIGHT)
                critical.push_back(edges[i][3]); 
            
            else if(Kruskal(edges, -1, i) == MST_WEIGHT)
                pseudo_critical.push_back(edges[i][3]);
        }

        return {critical, pseudo_critical};



    }
};