class Solution {
public:
    int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
	int dy[8] = {1, -1, 0, 0, -1, 1, -1, 1};
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                 int ones=0;
                for(int k=0;k<8;k++)
                {
                    int nr=i+dx[k];
                    int nc=j+dy[k];
                   
                    if(nr>=0 && nr<m && nc>=0 && nc<n)
                    {
                       if(board[nr][nc]==1)
                       {
                           ones++;
                       }
                    }
                }
                if(board[i][j]==0 && ones==3)
                {
                    vis[i][j]=1;
                }
                else if(board[i][j]==1 && ones<2)
                {
                    vis[i][j]=0;
                }
                else if(board[i][j]==1 && (ones==2 || ones==3))
                {
                    vis[i][j]=1;
                }
                else
                {
                    vis[i][j]=0;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                board[i][j]=vis[i][j];
            }
        }
    }
};