//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
   vector<int> prevSmall(int arr[],int n)

    {

        stack<int> s;

        vector<int> res(n);

        for(int i=0;i<n;i++)

        {

            while(!s.empty() && arr[s.top()]>=arr[i])

            s.pop();

            

            if(s.empty()) res[i]=0;

            else res[i]=arr[s.top()];

            s.push(i);

            

        }

        return res;

    }

     vector<int> nextSmall(int arr[],int n)

    {

        stack<int> s;

        vector<int> res(n);

        for(int i=n-1;i>=0;i--)

        {

            while(!s.empty() && arr[s.top()]>=arr[i])

            s.pop();

            

            if(s.empty()) res[i]=0;

            else res[i]=arr[s.top()];

            s.push(i);

            

        }

      

        return res;

    }

    int findMaxDiff(int arr[], int n)

    {

      //Your code here

      vector<int> ps = prevSmall(arr,n);

      vector<int> ns = nextSmall(arr,n);

      int res=0;

      

      for(int i=0;i<n;i++)

      {

          int diff=abs(ps[i]-ns[i]);

          res=max(res,diff);

      }

      return res;

      

    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
   	int n;
   	cin>>n;
   	int a[n];
   	for(int i=0;i<n;i++)
   	cin>>a[i];
   	Solution ob;
   	cout<<ob.findMaxDiff(a,n)<<endl;
   }
    return 0;
}



// } Driver Code Ends