class Solution {
public:
    // int dx[8]={-1,-1,0,1,1,1,0,-1};
    // int dy[8]={0,-1,1,1,0,-1,-1,-1};
    int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
	int dy[8] = {1, -1, 0, 0, -1, 1, -1, 1};

    int mini=INT_MAX;
    // int solve(vector<vector<int>>&grid,int i,int j,int cell,vector<vector<int>>&dp)
    // {
    //     int n=grid.size();
    //     if(i==n-1 && j==n-1 && grid[i][j]==0)
    //     {
    //         mini=min(mini,cell);
    //         return ;
    //     }
    //     for(int a=0;a<8;a++)
    //     {
    //         int nr=i+dx[a];
    //         int nc=j+dy[a];
    //         if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nc][nr]==0)
    //         {
    //             int ans=1+solve(grid,i,j,mini,dp);
    //             mini=min(ans,mini);
    //         }
    //     }
    //    // return mini;

    // }


    int shortestPathBinaryMatrix(vector<vector<int>>& a) {
        int n = a.size();
		if (a[0][0] != 0 || a[n - 1][n - 1] != 0)
		{
			return -1;
		}
        queue<pair<int,int>>q;
        q.push({0,0});
        int step=0;
        int size=0;
        int x , y, newx, newy;
        while(!q.empty())
        {
            step++;
            size=q.size();
            while(size--)
            {
                x = q.front().first;
				y = q.front().second;
				q.pop();
				if (x == n - 1 && y == n - 1)
				{
					return step;
				}
                for(int k=0;k<8;k++)
        {
            int nr=x+dx[k];
            int nc=y+dy[k];
            if(nr>=0 && nr<n && nc>=0 && nc<n && a[nr][nc]==0 )
            {
             a[nr][nc]=1;
                q.push({nr,nc});
            }
        }
            }
        }       
    return -1;
    }
};