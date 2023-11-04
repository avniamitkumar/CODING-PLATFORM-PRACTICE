class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        int i=0;
        int n=arr.size();
        while(i<n)
        {
            int c=arr[i]-1;
            if(arr[c]!=arr[i])
            {
                swap(arr[c],arr[i]);
            }
            else
            {
                i++;
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=i+1)
            {
                ans.push_back(arr[i]);
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};