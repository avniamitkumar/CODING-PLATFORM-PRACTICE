//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
         // code here
        queue<pair<int,int>>q;
        // the start is used to to provide the input into the queue so that's why we cannnot make it zero
        q.push({start,0});
        // the values at the distance vector is inintialized to infinity
        vector<int>dist(100000,1e9);
        
        // initialize the starring vector zero
        // for example if start=3 then dist[3]=0 i.e making 3 as the source node
        dist[start]=0;
        int mod=100000;
        while(!q.empty())
        {
            int node=q.front().first;
            int steps=q.front().second;
            q.pop();
            // iterating the array
            // for example if the array is{2,3,7}
            for(auto it:arr)
            {
                // 2*3=6, agin the iterator increases 6*3=18 again the iterator increases 3*7=21 agin the each ierator values are multiolied with 2,3,7
                int num=(it*node) % mod;
                // checks if the steps is less then the adjacnet node  steps
                if(steps+1<dist[num])
                {
                    // if yes,then change the value of the current node setep to +1
                    dist[num]=steps+1;
                    
                    // if we found the number then we can just return the steps +1;
                    if(num==end)
                    return steps+1;
                    q.push({num,steps+1});
                }
                
            }
        }
        return -1;
    
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends