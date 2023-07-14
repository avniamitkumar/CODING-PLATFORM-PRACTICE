//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   bool isPossible(vector<int>&arr,int m,int k,int given)
    {
        int cur=0;
        int n=arr.size();
        int temp=0;
        for(int i=0;i<n;i++)
        {
            if(temp==k)
            {
                cur++;
                temp=0;
            }
            if(arr[i]<=given)
            {
                temp++;
            }
            else
            {
                temp=0;
            }
        }
            if(temp==k){
            cur++;
            temp = 0;
        }
        
        return cur>=m;
    }

    int BinarySearch(vector<int>& arr, int m, int k)
    {
        int st=1;
        int end=INT_MIN;
        for(int i=0;i<arr.size();i++)
        {
            end=max(arr[i],end);
        }
        int ans=-1;
        while(st<=end)
        {
            int mid=st+(end-st)/2;
            if(isPossible(arr,m,k,mid)==true)
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
               st= mid+1;
            }
        }
        return ans;

    }



    int solve(int M, int K, vector<int> &v){
      // Code here
         if(v.size()<M*K)
            return -1;
        int lo=1,hi=INT_MAX,ans=-1;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            int flowers=0,bouq=0;
            for(int i=0;i<v.size();i++)
                {
                    if(v[i]<=mid)
                        flowers++;
                    else
                        flowers=0;
                    if(flowers==K)
                        {
                            bouq++;
                            flowers=0;
                        }
                }
            if(bouq>=M)
                {
                    ans=mid;
                    hi=mid-1;
                }
            else
                lo=mid+1;
        }
    return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends-