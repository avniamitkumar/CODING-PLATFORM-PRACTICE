//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  void solve(vector<int>v,int k,int indx,int &ans)
    {
        //base condition
        if(v.size()==1)
        {
            ans=v[0];
            return ;

        }
        indx=(indx+k)%v.size();
        v.erase(v.begin()+indx);
        solve(v,k,indx,ans);
    }
    int safePos(int n, int k) {
        // code here
        //Your code here
      vector <int>arr;
      for(int i=1;i<=n;i++)
      {
          arr.push_back(i);
      }
      k=k-1;
      int indx=0;
      int ans=-1;
      solve(arr,k,indx,ans);
      return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    }
    return 0;
}
// } Driver Code Ends