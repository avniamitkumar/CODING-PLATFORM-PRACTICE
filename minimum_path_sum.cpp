class Solution {
public:
//RECURSION
int solve(int m,int n,vector<vector<int>>& grid)
	{
	    if(m==0 && n==0)
	    {
	        return grid[0][0];
	    }
	    if(m<0 || n<0 )return 1e9;
    
	   int b=solve(m,n-1,grid)+grid[m][n];
	   int d=solve(m-1,n,grid)+grid[m][n];
	    return min(b,d);
	}
	//MEMOIZATION
	int solve2(int m,int n,vector<vector<int>>& grid,vector<vector<int>>&dp)
	{
		if(m==0 && n==0)
	    {
	        return grid[0][0];
	    }
			if(m<0 || n<0 )return 1e9;
			if(dp[m][n]!=-1)
			{
				return dp[m][n];
			}
			int b=solve(m,n-1,grid)+grid[m][n];
	   int d=solve(m-1,n,grid)+grid[m][n];
	    return dp[m][n]=min(b,d);

	}
		//TABULATION
		int solve3(vector<vector<int>>& grid)
		{
			int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>>dp(row, vector<int>(col, 0));
				for(int i=0;i<row;i++)
				{
					for(int j=0;j<col;j++)
					{	
						if(i==0 && j==0)
						{
								dp[i][j]=grid[0][0];
						}else{
							int b=0;
							int d=0;
						if(j>0)b=dp[i][j-1]+grid[i][j];
						else b+= 1e9;
						if(i>0) d=dp[i-1][j]+grid[i][j];
						else d+= 1e9;
						dp[i][j]=min(b,d);}
					}
				}
					return dp[row-1][col-1];

		}



    int minPathSum(vector<vector<int>>& grid) {
      //  int m = grid.size();int n = grid[0].size();
 				//vector<vector<int>>dp(m, vector<int>(n, -1));
				 return solve3(grid);
        // return solve2(m-1, n-1, grid, dp);

      //  return solve (m-1,n-1,grid);
    }
};