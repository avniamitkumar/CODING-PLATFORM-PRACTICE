//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
    int kthElement(int arr1[], int arr2[], int n, int m, int ku)
    {
        int arr3[m+n];
        int i = 0, j = 0, k = 0;
      // traverse the arr1 and insert its element in arr3
      while(i < n){
      arr3[k++] = arr1[i++];
    }
       
      // now traverse arr2 and insert in arr3
      while(j < m){
      arr3[k++] = arr2[j++];
    }
       
      // sort the whole array arr3
      sort(arr3, arr3+m+n);
        
        int st=0;
        int end=k;
        while(st<=end)
        {
            int mid=st +(end-st)/2;
            if(mid==ku)
            {
                return arr3[ku-1];
            }
            else if(mid>ku)
            {
                end=mid-1;
            }
            else
            {
                st=mid+1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends