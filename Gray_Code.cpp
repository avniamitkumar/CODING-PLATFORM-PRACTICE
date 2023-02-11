//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    
    
    
    vector<string> graycode(int n)
    {
        //code here
        if(n==1)
        {
            return {"0","1"};
        }
        vector<string> chotaans=graycode(n-1);
        vector<string> badaans;
        for(int i=0;i<chotaans.size();i++){
            string s=chotaans[i];
            badaans.push_back("0"+s);
      }
      for(int i=chotaans.size()-1;i>=0;i--){
          string s=chotaans[i];
          badaans.push_back("1"+s);
      }
      return badaans;
        
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
        
        Solution ob;
        vector<string> ans= ob.graycode(n);
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
            
        cout<<"\n";
    }
}




// } Driver Code Ends