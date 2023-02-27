//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code 
        int prefix[n];
        int suffix[n];
        int prev=-1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>prev)
            {
                prefix[i]=arr[i];
                prev=arr[i];
            }
            else
            {
                prefix[i]=prev;
            }
          //  cout<<prefix[i]<<" ";
        }
       // cout<<endl;
        int next=-1;
        //int prev=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]>next)
            {
                suffix[i]=arr[i];
                next=arr[i];
            }
            else
            {
                suffix[i]=next;
            }
           // cout<<suffix[i]<<" ";
        }
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=(min(prefix[i],suffix[i]))-arr[i];
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends