//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& pre) {
	    // Code here
	     int V=n;
          vector<int>adj[n];

         for(auto it: pre){

            int u = it.first ;
       int v = it.second ; adj[ u ].push_back( v ); 

         }
       // vector<int>topo;
        queue<int>q;
	//    int indegree[n]={0};
			vector<int>indegree(n,0);
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    //o(v+e)
	    vector<int>topo;
	    int cnt=0;
	    while(!q.empty())
	    {
	        topo.push_back(q.front());
	        int node=q.front();
	        q.pop();
	        cnt++;
	        for( auto it:adj[node])
	        {
	            indegree[it]--;
	            
	            if(indegree[it]==0)
	            {
	                q.push(it);
	            }
	        }
	      
	    }
	    if(cnt==V)return true;
          return 0;
        
        
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends