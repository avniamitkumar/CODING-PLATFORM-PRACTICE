//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minimumTime(int n,int cur,vector<int> &pos,vector<int> &time){
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back(make_pair(pos[i],time[i]));
        }
        int min=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int m=(abs(cur-v[i].first))*(v[i].second);
            if(m<min)
            {
                min=m;
            }
            
        }
        return min;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,cur;
        cin>>N>>cur;
        vector<int> pos(N),time(N);
        for(int i=0;i<N;i++){
            cin>>pos[i];
        }
        for(int i=0;i<N;i++){
            cin>>time[i];
        }
        Solution ob;
        cout<<ob.minimumTime(N,cur,pos,time)<<endl;
    }
}
// } Driver Code Ends