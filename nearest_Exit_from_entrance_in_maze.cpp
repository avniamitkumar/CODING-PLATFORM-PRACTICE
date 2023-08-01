class Solution {
public:
    int nearestExit(vector<vector<char>>& mat, vector<int>& ent) {
        int r=ent[0];
        int c=ent[1];
        int n=mat.size();
        int m=mat[0].size();
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        queue<pair<int,int>>q;
        q.push({r,c});
        int st=0;

        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[r][c]=1;
        while(!q.empty())
        {
              int size = q.size();
            for(int j = 0; j < size; j++) {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
          //  st++;
          //  vis[row][col]=1;
            for(int i=0;i<4;i++)
            {
                int nr=dr[i]+row;
                int nc=dc[i]+col;
                if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc]=='.' && vis[nr][nc]==0)
                {
                    if(nr==n-1 || nr==0 )return st+1;
                    else if(nc==m-1 || nc==0)return st+1;
                    else q.push({nr,nc}); vis[nr][nc]=1;
                } 
            }
        }
            st++;
        }
        return -1;

    }
};