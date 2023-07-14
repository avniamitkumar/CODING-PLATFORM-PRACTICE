class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
        int n=arr.size();
       
        sort(arr.begin(),arr.end());
         int ans=arr[0]+arr[1]+arr[2];
        for(int i=0;i<n;i++)
        {
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                int sum=0;
                sum+=arr[i];
                sum+=arr[j];
                sum+=arr[k];
                int diff=abs(target-sum);
                int prev=abs(ans-target);

                if(diff<prev)
                {
                    ans=sum;
                }
                 if(sum>target)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        return ans;
    }
};