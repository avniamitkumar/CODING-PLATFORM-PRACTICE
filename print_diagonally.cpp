//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int N, vector<vector<int>> A)
	{
	    vector <int>my;
		// Your code goes here
		for(int i=0;i<N;i++)
    {
        int row=0,col=i;
        while(col>=0)
        {
            
            my.push_back(A[row++][col--]);
            //cout<<arr[row++][col--]<<" ";
        }
    }
    for(int j=1;j<N;j++)
    {
        int row=j,col=N-1;
        while(row<N)
        {
            my.push_back(A[row++][col--]);
            //cout<<arr[row++][col--]<<" ";
        }
    }
    return my;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends