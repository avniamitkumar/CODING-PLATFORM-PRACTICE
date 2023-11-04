class Solution {
public:
    int minMoves2(vector<int>& arr) {
        sort(arr.begin(),arr.end()); int n=arr.size();
        if (n == 0) {
            return 0;  // You can choose to return 0 or handle it differently.
        }
       
        int mid;//;;/=(nums[0]+nums[n-1])/2;
        if(n%2!=0)
        {
            mid=arr[(n/2)];
        }
        else
        {
            int a=n/2;
            int b=a-1;
            mid=(arr[a]+arr[b])/2;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=abs(mid-arr[i]);
        }
        return ans;
    }
};