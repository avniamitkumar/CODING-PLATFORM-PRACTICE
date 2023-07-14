class Solution {
public:
    int arrayPairSum(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int ans=0;
        for(int i=0;i<n-1;i++)
        {

            ans+=min(arr[i],arr[i+1]);
            i++;
        }
        return ans;
    }
};