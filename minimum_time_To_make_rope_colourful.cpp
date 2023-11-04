class Solution {
public:
    int minCost(string c, vector<int>& arr) {
        int n=c.size();
        int ans=0;
        int i=0;
        while(i<n)
        {
            int mx=arr[i];
            int j=i+1;
            int sum=mx;
            while(j<n && c[i]==c[j])
            {
                sum+=arr[j];
                mx=max(mx,arr[j]);
                j++;
            }
            ans+=(sum-mx);
            i=j;
        }
        return ans;
    }
};