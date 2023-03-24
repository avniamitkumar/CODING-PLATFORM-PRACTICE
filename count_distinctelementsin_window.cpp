//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int arr[], int n, int k)
    {
        //code here.
        int hash[100000]={0};
        int i=0;
        int j=0;
        int cnt=0;
        vector<int>a;
        while(j<n)
        {
            hash[arr[j]]++;
            if(hash[arr[j]]==1)
            {
                cnt++;
            }
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                hash[arr[i]]--; 
                a.push_back(cnt);
                if(hash[arr[i]]==0)
                {
                    cnt--;
                }
                
                i++;
                j++;
                /*for(int i=0;i<hash.size();i++)
                {
                    hash[i]=0;
                }
                cnt=0;*/
               
            }
            
            
        }
        
        return a;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends