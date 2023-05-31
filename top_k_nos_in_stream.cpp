//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
  struct cf{
    bool operator()(pair<int, int> &p1, pair<int, int> &p2)
    {
        if(p1.second==p2.second)
        {
            return p1.first<p2.first;
        }
        return p1.second>p2.second;
    }
    
};
    void solve(int a[],int n,int k,vector<int>&abs)
    {
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[a[i]]++;
        }
       // priority_queue<pair<int,string>>pq;
        //priority_queue<pair<int,int>,greater<int,int>>pq;
         priority_queue<pair<int, int>, vector<pair<int, int>>, cf> pq;
        for(auto i:mp)
        {
             pq.push({i.first,i.second});
            while(pq.size()>k)
            {
                pq.pop();
            }
           
        }
        vector<int>ab;
        while(!pq.empty())
        {
            ab.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ab.begin(),ab.end());
        for(int i=0;i<ab.size();i++)
        {
            abs.push_back(ab[i]);
        }
       // return abs;
    }
    vector<int> kTop(int a[], int n, int k) 
    { 
        //code here.
        int b[n];
        vector<int>abs;
        for(int i=0;i<n;i++)
        {
            b[i]=a[i];
            
            solve(b,i,k,abs);
        }
        solve(a,n,k,abs);
        return abs;
    }
};


//{ Driver Code Starts.

int main() {
	long long t;
	
	cin >> t;
	
	while(t--){
	    long long n;
	    long long k;
	    cin >> n;
	    cin >> k;
	    int a[n];
	    for(long long i = 0;i<n;i++){
	        cin >> a[i];
	    }
	        Solution ob;
	        vector<int> ans;
	        ans=ob.kTop(a,n,k);
	        for(int i=0;i<ans.size();i++)
	        {
	        cout<<ans[i];
	        cout<<" ";
	        }
	        cout<<'\n';
	    }
	return 0;
}

// } Driver Code Ends