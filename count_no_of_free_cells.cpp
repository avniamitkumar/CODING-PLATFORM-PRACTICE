//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      //Code Here
      long fre=n*n;
      vector<bool>ro(n);
      vector<bool>co(n);
      int rc=0;
      int cc=0;
      vector<long long int>ans(k);
      for(int i=0;i<k;i++)
  {
        int row = arr[i][0];
        int col = arr[i][1];
        if(!ro[row-1])
        {
            fre=fre-(n-cc);
            ro[row-1]=1;
            rc++;
        }
        if(!co[col-1])
        {
            fre=fre-n+rc;
            co[col-1]=1;
            cc++;
        }
        ans[i]=fre;  
      
  }
     return ans; 
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends