//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
vector<int>arr;
    void precompute(){
        int n=1e6+1;
        vector<bool> prime(1e6+1,true);
        prime[0]=false;
        prime[1]=false;
        for(int i=2;i<n;i++)
        {
            if(prime[i]==true)
                { arr.push_back(i);
            for(int p=2*i;p<n;p=p+i)
            {
                prime[p]=false;
            }}
        }
      
        
    }
    void dfs(int st,vector<int>&vis,vector<vector<int>>&g,int &s)
    {
        s++;
        vis[st]=1;
       // s++;
        for(auto it:g[st])
        {
            if(!vis[it])
            {
                dfs(it,vis,g,s);
            }
        }
    }
    int helpSanta(int n, int m, vector<vector<int>> &g){
        // Code here
        vector<int>vis(n+1,0);
        int maxi=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                int s=0;
                dfs(i,vis,g,s);
                maxi=max(s,maxi);
            }
            
        }
        if(maxi==1)return -1;
        return arr[maxi-1];
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends