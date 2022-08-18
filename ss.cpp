#include <iostream>
using namespace std;
int main()
{
    int arr[9]={1,2,3,4,5,6,7,8,9};
    string name[9]={"one","two","three","four","five","six","seven","eight","nine"};
    int n;
    if(n<1 || n>1000000000)
    {return 0;}
    if(n>=1 && n<=9)
    {
        for(int i=0;i<n;i++)
        {
            if(arr[i]==n)
            {
                cout<<name[i];
            }
        }
    }
    else
    {
        cout<<"Greater than 9";
    }
    return 0;
}
