//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


int* game_with_number(int arr[], int n);

int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        int *arr2;
        
        arr2 = game_with_number(arr, n);
        for(int i = 0;i < n; i++)
            cout << arr2[i] << " ";
        
        cout << endl;
        
    }

}

// } Driver Code Ends


int* game_with_number(int arr[], int n)
{
    
    // Complete the function
    int prev=arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        int a=arr[i];
        arr[i]=arr[i]|prev;
       prev=a;
        
    }
    return arr;
    
}
