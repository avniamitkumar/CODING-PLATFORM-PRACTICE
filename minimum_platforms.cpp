//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	int platforms=1;
    	vector<pair<int,int>>my;
    	for(int i=0;i<n;i++)
    	{
    	    my.push_back({arr[i],dep[i]});
    	    
    	}
    	priority_queue<int, vector<int>, greater<int>> pq;
    	 sort(my.begin(), my.end());
    //	vector<vector<pair<int,int>>>v;	bool track[n];
    	
    	
    	pq.push(my[0].second);
    	for(int i=1;i<n;i++)
    	{
    	    int mini=pq.top();
    	    if(my[i].first<=mini)
    	    {
    	        platforms++;
    	    }else
    	    {
    	        pq.pop();
    	    }
    	    pq.push(my[i].second);
    	}
    	return platforms;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends