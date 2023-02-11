// C++ implementation of the above approach:

#include <bits/stdc++.h>
using namespace std;

// Function to print the outpu
void solve(int n,vector<int>&ds,vector<vector<int>>&ans,int ind)
{
    if(ind==n)
    {
        ans.push_back(ds);
        for(int i=0;i<ds.size();i++)
        {
            cout<<ds[i];
        }
        cout<<endl;
        return;
    }
    ds.push_back(0);
    solve(n,ds,ans,ind+1);
    ds.pop_back();
    ds.push_back(1);
    solve(n,ds,ans,ind+1);
    ds.pop_back();
}


// Function to generate all binary strin

// Driver Code
int main()
{
    vector<int>ds;
    vector<vector<int>>ans;
    
	solve(3,ds,ans,0);
	

	return 0;
}
