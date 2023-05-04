//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        if(n==1)return arr[0];
        //nsl
        stack<long long>s;
        vector<int>l;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && arr[s.top()]>=arr[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                l.push_back(-1);
            }
            else
            {
                l.push_back(s.top());
            }
            s.push(i);
        }
         vector<long long>right;
        stack<long long>s1;
        for(int i=n-1;i>=0;i--){
            while(!s1.empty() && arr[s1.top()]>=arr[i]){
                s1.pop();}
            if(s1.empty()){
                right.push_back(n);}
            else{
                right.push_back(s1.top());}
            s1.push(i);}
            reverse(right.begin(),right.end());
        vector<long long>width;
        for(int i=0;i<n;i++){
            width.push_back((right[i]-l[i]-1)*arr[i]);}
        long long ans=width[0];
        for(int i=1;i<n;i++){
            ans=max(ans,width[i]);}
        return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends