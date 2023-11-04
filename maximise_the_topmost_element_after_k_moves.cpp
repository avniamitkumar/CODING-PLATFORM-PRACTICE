class Solution {
public:
    int maximumTop(vector<int>& arr, int k) {
        int n=arr.size();
        int maxi=-1;
        if(arr.size() == 1 and k%2 == 1) return maxi;
        
        for(int i=0;i<=k && i<n;i++)
        {
            if(i!=k-1)maxi=max(maxi,arr[i]);
        }
        return maxi;
    }
};