//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        //code here
        sort(a,a+n);
        sort(b,b+m);
        int cnt=0;
        int c[m+n];
        int i=0,j=0,k=0;
        while(i<n && j<m)
        {
            if(a[i]<b[j])
            {
                if(k!=0 && a[i]==c[k-1])
                {
                    i++;
                }else{
                c[k++]=a[i++];}
            }
            else
            {
                if(k!=0 && b[j]==c[k-1] )
                {
                   
                    j++;
                }else{
                c[k++]=b[j++];
                }
            }
        }
        while(i<n)
        {
            if(k!=0 && a[i]==c[k-1])
            {
                i++;
            }
            else{
            c[k++]=a[i];
            i++;}
        }
        while(j<m)
        {
            if(k!=0 && b[j]==c[k-1])
            {
                j++;
            }else
            {
            c[k++]=b[j];
            j++;
        }}
        return k;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends