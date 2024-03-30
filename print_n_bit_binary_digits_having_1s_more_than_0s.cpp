//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    void solve(vector<string>&ans,string &ds,int ind ,int n,int z,int o)
    {
        if(ind==n)
        {
                ans.push_back(ds);
            return ;
        }
        ds+='1';
        solve(ans,ds,ind+1,n,z,o+1);
        ds.pop_back();
        if(o>z)
        {
            ds+='0';
            solve(ans,ds,ind+1,n,z+1,o);
            ds.pop_back();
        }
    }
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    	vector<string>ans;
	    	string ds="";
	    	solve(ans,ds,0,n,0,0);
	    	return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends