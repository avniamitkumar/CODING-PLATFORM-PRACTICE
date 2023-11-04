class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n=arr.size();
        int low=0;
        int ans=0;
        int high=n-1;
        while(low<high)
        {
            ans=max(ans,(min(arr[low],arr[high]))*(high-low));
            if(arr[low]<=arr[high])
            {
                low++;
            }
            else
            {
                high--;
            }
        }
        return ans;



        // int n=arr.size();
        // int ans=0;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=i+1;j<n;j++)
        //     {
        //         ans=max(ans,(min(arr[i],arr[j]))*(j-i));
        //     }
        // }
        // return ans;
    }
};