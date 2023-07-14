class Solution {
public:
    vector<int> dailyTemperatures(vector<int>&arr) {
        vector<int>ans;
        stack<pair<int,int>>st;
        int n=arr.size();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top().first]<=arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(st.top().first-i);
            }
            st.push({i,arr[i]});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};