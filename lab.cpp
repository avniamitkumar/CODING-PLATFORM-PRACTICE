#include <bits/stdc++.h>
using namespace std;

template <class T,int len>
class arra
{
public:
	T arr[len];
	array()
	{
		for(int i=0;i<len;i++)
		{
			arr[i]=0;
		}
	}
	void start(int *a)
	{
		for(int i=0;i<len;i++)
		{
			arr[i]=a[i];
		}
	}

	void find(T key)
	{
	for(int i=0;i<len;i++)
	{
	if(arr[i]==key)
		{
		cout<<"KEY FOUND AT "<<i<<endl;
		break;
		}
	}
	if(arr==len)
	{
	cout<<"KEY NOT FOUND"<<endl;
	}
	}
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	arra <int,len> my;
	my.start(a);
	my.find(12);
	return 0;
}