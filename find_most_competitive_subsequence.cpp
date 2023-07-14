class Solution {
public:
    vector<int>which(vector<int>&a,vector<int>&b,int k)
    {
        for(int i=0;i<k;i++)
        {
            if(a[i]>b[i])
            {
                return b;
            }
            if(b[i]>a[i])
            {
                return a;
            }
        }
        return {};
    }


    vector<int> mostCompetitive(vector<int>& arr, int k) {
        int n=arr.size();
        stack<int>st;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            
            while(!st.empty() && arr[st.top()]>arr[i] && st.size()+(n-i)>k)
            {
                st.pop();
            }
            // if(st.size()==k)
            // {
            //     vector<int>a;
            //     a.push_back(arr[st.top()]);
            //     st.pop();
            //     reverse(a.begin(),a.end());
            //     ans=which(ans,a,k);
            // }
            st.push(i);
        }
          while (!st.empty())
        {
            while(st.size()>k)
                st.pop();
        
                ans.push_back(arr[st.top()]);
                st.pop();
            
        }
        
        reverse(ans.begin(),ans.end());
        return ans;

    }
};