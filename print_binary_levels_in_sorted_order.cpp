//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    vector <vector <int>> binTreeSortedLevels (int arr[], int n)
    {
        // Your code here
        vector<vector<int>>ans;
        queue<int>q;
        int j=0;
        q.push(arr[j]);
        q.push(-1);
        while(!q.empty())
        {
            vector<int>temp; int size=q.size();
             for(int i=0;i<size;i++)
            {
                if(q.front()!=-1)
                {
                   
                    int node=q.front();
                    temp.push_back(node);
                    q.pop();
                    if(2*j+1<n)
                    {
                        q.push(arr[2*j+1]);
                    }
                    if(2*j+2<n)
                    {
                        q.push(arr[2*j+2]);
                    }
                    j++;
                }
                else
                {
                    sort(temp.begin(),temp.end());
                      ans.push_back(temp);
                      q.pop();
                      q.push(-1);
                       if(q.front()==-1)return ans;
                }
            
                    
                }
            
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i)
			cin >> arr[i];

        Solution ob;
        
		vector <vector <int>> res = ob.binTreeSortedLevels (arr, n);
		for (int i = 0; i < res.size(); ++i)
		{
			for (int j = 0; j < res[i].size(); ++j)
			{
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
	}
}

// Contributed By: Pranay Bansal
// } Driver Code Ends