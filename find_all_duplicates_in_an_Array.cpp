class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        int n=arr.size();
        int i=0;
        while(i<n)
        {
            int c=arr[i]-1;
            if(arr[c]!=arr[i])
            {
                swap(arr[i],arr[c]);
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
            }
        }
        return ans;
    }
};