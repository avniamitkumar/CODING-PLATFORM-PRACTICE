class Solution {
public:
    int maxSubarrayLength(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        int n=arr.size();
        int i=0;
        int len=INT_MIN;
        int j=0;
        while(j<n)
        {
            mp[arr[j]]++;
            while(i<n && mp[arr[j]]>k)
            {
                mp[arr[i++]]--;
            }
            len=max(len,j-i+1);
            j++;
        }
        return len;
    }
};