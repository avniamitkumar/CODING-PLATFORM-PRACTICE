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



    int makeConnected(int n, vector<vector<int>>& c) {
        int lines=c.size();
        parent.resize(n);
        rank.resize(n,0);
        if(lines<n-1)return -1;
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        int comp=n;
        for( auto &vec:c)
        {
            if(find(vec[0])!=find(vec[1]))
            {
                Union(vec[0],vec[1]);
                comp--;
            }
        }
        return comp-1;
    }
};