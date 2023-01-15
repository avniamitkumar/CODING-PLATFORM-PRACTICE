//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void solve(vector<int>&arr,vector<int>&ds,vector<vector<int>> &ans,int ind,int sum)
    {
        if(ind==arr.size())
        {
            if(sum==0)
            {
                
                ans.push_back(ds);
            }
            return;
        }
        if(arr[ind]<=sum){
        ds.push_back(arr[ind]);
       // sum=sum-arr[ind];
        solve(arr,ds,ans,ind,sum-arr[ind]);
        ds.pop_back();
       // sum=sum+arr[ind];
       }
        solve(arr,ds,ans,ind+1,sum);
    }


    
    
    vector<vector<int> > combinationSum(vector<int> &c, int target) {
        // Your code here
        set<int>s;
        for(auto it:c)s.insert(it);
        vector<int>L;
        for(auto it:s){L.push_back(it);}
        vector<vector<int>> ans;
        int n=L.size();
        vector<int>ds;
         
        solve(L,ds,ans,0,target);
         sort(c.begin(),c.end());
        return ans;
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends