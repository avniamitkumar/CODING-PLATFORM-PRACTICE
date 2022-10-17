//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A,A+n);
       //int i=0,j=n-1;
       for(int l=0;l<n-2;l++)
      {
          int i=l+1;
          int j=n-1;
          while(i<j)
          {
              if(A[i]+A[l]+A[j]==X)
              {
                  return true;
              }
              else if(A[l]+A[i]+A[j]<X)
              {
                  i++;
              }
              else
              {
                  j--;
              }
          }
      }
      return false;
       }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends