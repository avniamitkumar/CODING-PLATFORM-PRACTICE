//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int v[], int n , int x )
{
        int st=0;
        int end=n-1;
        int f=-1,l=-1;
        vector <int>my;
        while(st<=end)
        {
            int mid=st + ((end-st)/2);
            if(v[mid]==x)
            {
                end=mid-1;
                f=mid;
            }
            else if(x<v[mid])
            {
                end=mid-1;
            }
            else
            {
                st=mid+1;
            }
        }
        st=0,end=n-1;
         while(st<=end)
        {
            int mid=st + ((end-st)/2);
            if(v[mid]==x)
            {
                l=mid;
                st=mid+1;
                
            }
            else if(x<v[mid])
            {
                end=mid-1;
            }
            else
            {
                st=mid+1;
            }
        }
        my.push_back(f);
        my.push_back(l);
        return my;
    }  



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends