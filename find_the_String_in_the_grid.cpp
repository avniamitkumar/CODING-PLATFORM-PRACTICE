//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    



	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	     int dx[]={-1,-1,0,1,1,1,0,-1};
        int dy[]={0,1,1,1,0,-1,-1,-1};
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==word[0])
                {
                    for(int k=0;k<8;k++)
                    {
                        int nrow=i+dx[k];
                        int ncol=j+dy[k];
                        int s=word.size();
                        int p=1;
                        while(nrow>=0 && nrow<n && ncol>=0 && ncol<m && p<s &&word[p]==grid[nrow][ncol])
                        {
                            nrow+=dx[k];
                            ncol+=dy[k];
                            p++;
                        }
                        if(p==s)
                        {
                            ans.push_back({i,j});
                            break;
                        }
                    }
                }
            }
        }
        return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends