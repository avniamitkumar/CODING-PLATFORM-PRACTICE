class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x)
    {
        if(parent[x]==x)
        {
            return x;
        }
        return parent[x]=find(parent[x]);
    }

    void Union(int x,int y)
    {
        int x_parent=find(x);
        int y_parent=find(y);
        if(rank[x_parent]>rank[y_parent])
        {
            parent[y_parent]=x_parent;
        }
        else if(rank[y_parent]>rank[x_parent])
        {
             parent[x_parent]=y_parent;
        }
        else
        {
             parent[x_parent]=y_parent;
             rank[y_parent]++;
        }
    }

    bool equationsPossible(vector<string>& equations) {
         parent.resize(26);
        rank.resize(26);
        
        for(int i = 0; i<26; i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        for(int i=0;i<equations.size();i++)
        {
            if(equations[i][1]=='=')
            {
                Union(equations[i][0]-'a', equations[i][3]-'a');
            }
        }

         for(int i=0;i<equations.size();i++)
        {
            if(equations[i][1]=='!')
            {
               if( find(equations[i][0]-'a')==find(equations[i][3]-'a'))return false;
            }
        }
    return true;
    }
};