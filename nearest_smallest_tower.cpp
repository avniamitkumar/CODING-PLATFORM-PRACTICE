//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        // code here
        int n=arr.size();
        vector<int>left;
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(st.size()>0&&arr[st.top()]>=arr[i]) st.pop();
            if(st.size()==0) left.push_back(-1);
            else left.push_back(st.top());
            st.push(i);
        }
        vector<int>right;
      stack<int>st1;
        for(int i=n-1;i>=0;i--)
        {
            while(st1.size()>0&&arr[st1.top()]>=arr[i]) st1.pop();
            if(st1.size()==0) right.push_back(-1);
            else right.push_back(st1.top());
            st1.push(i);
        }
        reverse(right.begin(),right.end());
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int dist1=abs(right[i]-i);
            int dist2=abs(left[i]-i);
            if(right[i]==-1&&left[i]==-1) 
            {
                ans.push_back(-1);
            }
            else if(right[i]==-1||left[i]==-1)
            {
                ans.push_back(right[i]!=-1?right[i]:left[i]);
            }
            else if(dist1==dist2)
            {
                ans.push_back(arr[right[i]]<arr[left[i]]?right[i]:left[i]);
            }
            else
            {
                ans.push_back(dist1<dist2?right[i]:left[i]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends