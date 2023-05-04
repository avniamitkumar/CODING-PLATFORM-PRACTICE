//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
   vector<pair<int,int>> allPairs(int a[], int b[], int n, int m, int sum){
        vector<pair<int,int>> ans;
        sort(a,a+n);
        set<int> s;
        for(int i=0;i<m;i++){
            s.insert(b[i]);
        }
        for(int i=0;i<n;i++){
            if(s.find(sum-a[i])!=s.end()){
                ans.push_back({a[i],sum-a[i]});
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
	long long t;
	cin >> t;
	
	while(t--){
	    int N, M, X;
	    cin >> N >> M >> X;
        int A[N], B[M];
        
	    for(int i = 0;i<N;i++)
	        cin >> A[i];
	    for(int i = 0;i<M;i++)
	        cin >> B[i];
	        
	   Solution ob;
	   vector<pair<int,int>> vp = ob.allPairs(A, B, N, M, X);
	   int sz = vp.size();
        if(sz==0)
        cout<<-1<<endl;
        else{
            for(int i=0;i<sz;i++){
                if(i==0)
                cout<<vp[i].first<<" "<<vp[i].second;
                else
                cout<<", "<<vp[i].first<<" "<<vp[i].second;
            }
            cout<<endl;
        }
	}
	return 0;
}
// } Driver Code Ends