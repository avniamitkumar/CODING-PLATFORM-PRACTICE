//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int save_gotham(int arr[], int n);



int main() {
    
    int t;
    cin>> t;
    while(t--)
    {
        int n;cin>>n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        cout << save_gotham(arr, n) << endl;
    }
    
	return 0;
}
// } Driver Code Ends


int save_gotham(int arr[], int n)
{
    // Complete the function
    stack<int>st;
    int sum=0;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && st.top()<=arr[i])
        {
            st.pop();
        }
        if(!st.empty()) sum= ((sum%1000000001)+(st.top()%1000000001));
        st.push(arr[i]);
    }
    return sum;
}