
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int a,b;
    string name[9]={"one","two","three","four","five","six","seven","eight","nine"};
    cin>>a>>b;
    for(int i=a;i<=b;i++)
    {
       if(i<=9)
       {
           cout<<name[i-1]<<endl;
       }
       if(i>9 && i%2==0)
       {
           cout<<"even"<<endl;
       }
       else if(i>9 && i%2!=0)
       {
           cout<<"odd"<<endl;
       }
    }
    return 0;
}
