class Solution {
public:
    int minPairSum(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int maxi=INT_MIN;
        int i=0;
        int j=n-1;
        while(i<j)
        {
            maxi=max(maxi,arr[i]+arr[j]);
            i++;
            j--;
        }
        return maxi;
    }
};