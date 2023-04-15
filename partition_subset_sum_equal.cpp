

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

bool safepartition(int N,int arr[],int index,int curr,int sum){
    if(index>=N){
        if(curr==sum){
            return true;
        }
        return false;
    }
    if(curr<=sum){
        return safepartition(N,arr,index+1,curr+arr[index],sum) || safepartition(N,arr,index+1,curr,sum);
    }
    else{
        return safepartition(N,arr,index+1,curr,sum);
    }
    
    
    
}
    int equalPartition(int N, int arr[])
    {
        // code here
       
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0){
            return 0;
        }
        return safepartition(N,arr,0,0,sum/2);
    }   
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends