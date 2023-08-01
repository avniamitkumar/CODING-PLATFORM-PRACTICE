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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        parent.resize(n,0);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                {
                    Union(i,j);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)c++;
        }
        return n-c;
    }
};