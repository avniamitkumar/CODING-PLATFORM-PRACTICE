// Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
using namespace std;
int hourglass(int a[6][6])
{
    int max=INT_MIN;
    int i,j,sum,mi,mj;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            sum=a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j+1]+a[i+2][j]+a[i+2][j+1]+a[i+2][j+2];
            if(sum>max)
            {
                max=sum;
                mi=i;
                mj=j;

            }
        }

    }
    return max;
}


int main() {
    int i=6,j=6;
    int arr[6][6];
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<hourglass(arr);
    return 0;
}
