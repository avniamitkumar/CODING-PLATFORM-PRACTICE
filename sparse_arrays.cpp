// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    string stringList[n];
    for(int i=0;i<n;i++)
    {
        cin>>stringList[i];
    }
    int q;
    cin>>q;
    string queries[q];
    for(int i=0;i<q;i++)
    {
        cin>>queries[i];
    }
    int result[q];
    for(int i=0;i<q;i++)
    {
        result[i]=0;
        for(int j=0;j<n;j++)
        {
            if(queries[i]==stringList[j])
            {
                result[i]++;
            }
        }
    }
    for(int i=0;i<q;i++)
    {
        cout<<result[i]<<endl;
    }
    
    
    
    return 0;
}