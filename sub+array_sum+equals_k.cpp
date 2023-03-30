class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
       unordered_map<int,int>mp;
       int cnt=0;
       int sum=0;
       int n=arr.size();
       for(int i=0;i<n;i++)
       {
           sum+=arr[i];
           if(sum==k)
           {
               cnt++;
           }
           
               if(mp.find(sum-k)!=mp.end())
               {
                      cnt=cnt+mp[sum-k];
               }
               mp[sum]++;
           
       }
    return cnt;
    }

};