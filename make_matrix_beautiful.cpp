//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        int sum[n]={0};
        int colsum[n]={0};
        int maxsum=0;
        for(int i=0;i<n;i++)
        {
         for(int j=0;j<n;j++)
         {
            sum[i] += matrix[i][j];
            colsum[i] += matrix[j][i];
         }
         if(maxsum<colsum[i] || maxsum<sum[i])
         {
          maxsum=max(colsum[i],sum[i]);  
         }
        }
       
        int ans=0;
        for(int i=0;i<n;i++)
        {
          ans+=maxsum-colsum[i];
        }
        return ans;
        
        
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends