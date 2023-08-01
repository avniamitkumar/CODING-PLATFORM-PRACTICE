//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string a){
		    // Code here
		    int n=a.size();
		    string ans="";
		    // vector<pair<int,int>>v(26,{0,0});
		        vector<pair<int,int>>v(26,{0,0});
		        for(int i=0;i<n;i++){
                v[a[i]-'a'].first++;
                v[a[i]-'a'].second=i;
                int k=-1;int x=1e9;
                for(int j=0;j<26;j++){
                    if(v[j].first==1 && v[j].second<x){
                        x=v[j].second;
                        k=j;
                    }}
                     if(k==-1) ans+='#';
                else ans+=('a'+k);
                }
		       return ans;
		  //  int n=s.size();
		  // map<char,int>mp;
		  //  string op="";
		  //  char prev=s[0];
		  //  for(int i=0;i<n;i++)
		  //  {
		  //      mp[s[i]]++;
		  //      bool o=false;
		  //      if(mp[prev]>1)
		  //      {
		  //          o=true;
		  //          bool f=false;
		  //          for(auto it:mp)
		  //          {
		  //              if(it.second==1)
		  //              {
		  //                  f=true;
		  //                  prev=it.first;
		  //                 // cout<<prev<<endl;
		  //                  break;
		  //              }
		  //          }
		  //          if(!f){op+='#';continue;}
		  //      }
		  //     op+=prev;

		        
		  //  }
		  //  return op;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends