#include <iostream>
#include <cstring>
using namespace std;

int solve(string s)
{
	int res=0;
	for(int i=0;i<s.size();i++)
	{
		res=res*10+(s[i]-'0');
	}
	return res;

}

int main()
{
	string s;
	cin>>s;
	cout<<solve(s)<<endl;

	return 0;
}