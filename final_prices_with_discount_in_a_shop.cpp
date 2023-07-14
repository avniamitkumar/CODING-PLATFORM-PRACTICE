class Solution {
public:
    vector<int> finalPrices(vector<int>& arr) {
        vector<int>ans;
        stack<int>st;
        for(int i=arr.size()-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                ans.push_back(arr[i]);
            }
            else
            {
                ans.push_back(arr[i]-arr[st.top()]);
            }
            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};