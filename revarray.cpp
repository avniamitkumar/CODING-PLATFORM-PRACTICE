#include <iostream>
using namespace std;

int main() {
	int t,n;
	cin>>t;
	int te=0;
	for(te=0;te<t;t++){
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	for(int i=n-1;i>=0;i--)
	{
	    cout<<arr[i]<<" ";
	}
	cout<<endl;}
	return 0;
}