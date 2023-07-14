//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        //next smaller right
        int nsr[n];
        int nsl[n];
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                nsr[i]=n;
            }
            else
            {
                nsr[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            st.pop();
        }
        
        //next smaller left
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                nsl[i]=-1;
            }
            else
            {
                nsl[i]=st.top();
            }
            st.push(i);
        }
        vector<int>op(n+1,0);
        for(int i=0;i<n;i++)
        {
            int len=nsr[i]-nsl[i]-1;
            op[len]=max(op[len],arr[i]);
        }
        for(int i=n-1;i>=1;--i)
        {
            op[i]=max(op[i],op[i+1]);
        }
        op.erase(op.begin());
        return op;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends