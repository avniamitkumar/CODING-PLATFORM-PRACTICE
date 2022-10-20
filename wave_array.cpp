//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// #include <algorithm>


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(int n, vector<int>& arr){
        vector<int> brr;
        // Your code here
        if(n%2==0)
        {
            for(int i=0;i<n;i++)
            {
                if(i%2!=0)
                {
                    brr.push_back(arr[i-1]);
                }
                else
                {
                    brr.push_back(arr[i+1]);
                }
            }
        }
         else if(n%2!=0)
        {
            int i=0;
            while(i<n-1)
            {
                if(i%2==0)
                {
                    brr.push_back(arr[i+1]);
                    i++;
                }
                else
                {
                    brr.push_back(arr[i-1]);
                    i++;
                }
            }
            brr.push_back(arr[n-1]);
            //cout<<arr[n-1]<<" ";
        }
        for(int i=0;i<n;i++)
        {
            arr[i]=brr[i];
        }
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    cin>>t; //Input testcases
    while(t--) //While testcases exist
    {
        cin>>n; //input size of array
        vector<int> a(n); //declare vector of size n
        for(int i=0;i<n;i++)
            cin>>a[i]; //input elements of array
        Solution ob;
        ob.convertToWave(n, a);

        for(int i=0;i<n;i++)
            cout<<a[i]<<" "; //print array
            
        cout<<endl;
    }
}
// } Driver Code Ends