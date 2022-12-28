//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        if(x==0 || x==1)
        {
            return x;
        }
        long long int st=0;
        long long int end=x/2;
        int ans=0;
        while(st<=end)
        {
            long long int mid=st+(end-st)/2;
            if(mid*mid==x)
            {
                return (int)mid;
            }
            else if(mid*mid>x)
            {
                end=mid-1;
                //ans=mid;
            }
            else
            {
                st=mid+1;
                ans=mid;
            }
        }
        return(int)ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends