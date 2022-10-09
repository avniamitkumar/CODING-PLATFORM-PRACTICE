// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int *leftro(int arr[],int n)
{
    int x=arr[0];
    for(int i=0;i<n-1;i++)
    {
        arr[i]=arr[i+1];
    }
    arr[n-1]=x;
    return arr;
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    int t;
    cin>>t;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<t;i++){
    leftro(arr,n);}
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<< " ";
    }

    return 0;
}
