//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(vector<vector<int>>&img,int r,int c,vector<vector<int>>&vis,int color,int ncolor,int n,int m)
    {
        if(r<0 || c<0 ||r>=n  ||c>=m||img[r][c]!=color || vis[r][c]==ncolor )
        {
            return;
        }
        vis[r][c]=ncolor;
        dfs(img,r+1,c,vis,color,ncolor,n,m);
        dfs(img,r-1,c,vis,color,ncolor,n,m);
        dfs(img,r,c-1,vis,color,ncolor,n,m);
        dfs(img,r,c+1,vis,color,ncolor,n,m);
    }
    


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        vector<vector<int>>vis=image;
        int iniColor = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        dfs(image,sr,sc,vis,iniColor,newColor,n,m);
        return vis;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends