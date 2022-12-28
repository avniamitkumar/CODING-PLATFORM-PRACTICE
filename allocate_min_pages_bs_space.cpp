//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isvalid(int arr[],int n,int s,int max)
    {
        int stud=1;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+arr[i];
            if(sum>max)
            {
                stud++;
                sum=arr[i];
            }
        }
        if(stud>s)
        {
            return false;
        }
        return true;
 }
    
    
    int findPages(int A[], int N, int M) 
    {
        //code here
        int res=-1;
        if(N<M)
        {
            return -1;
        }
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum=sum+A[i];
        }
        int l=*max_element(A,A+N);
        int h=sum;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            
            if(isvalid(A,N,M,mid)==true)
            {
                res=mid;
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends