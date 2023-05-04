//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int firstElement(int arr[], int n, int k)

    { int max=arr[0];

      for(int i=1;i<n;i++){

          if(arr[i]>max)

          max=arr[i];

      }

      int hash1[max+1];

      int hash2[max+1];

      for(int i=0;i<max+1;i++){

          hash1[i]=0;

          hash2[i]=0;

      }

      for(int i=0;i<n;i++){

          hash1[arr[i]]++;

      }

      int c=-1;

      for(int i=n-1;i>=0;i--){

          hash2[arr[i]]++;

          if(hash2[arr[i]]==k && hash1[arr[i]]==k )

         { c=arr[i];} 

      }

      return c;

    }

    


};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		cout<<ob.firstElement(a,n,k)<<endl;
	}
	return 0;
}

// } Driver Code Ends