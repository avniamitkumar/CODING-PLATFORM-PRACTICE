//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int n)
    {
        
        // your code here
        int ele=0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(cnt==0)
            {
                ele=a[i];
            }
            if(ele==a[i])
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        int prev=0;
       for(int i=0;i<n;i++){
           if(a[i]==ele)prev++;
       }
        
        if(prev>n/2)return ele;
        return -1;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends