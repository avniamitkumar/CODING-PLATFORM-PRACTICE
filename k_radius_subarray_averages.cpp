class Solution {
public:
    vector<int> getAverages(vector<int>& arr, int k) {
        int i=0;
        int n=arr.size();
        int j=0;
        vector<int>ans(n,-1);
        long long req_len=2*k+1;
        long long sum=0;
        while(j<n)
        {
            sum+=arr[j];
            if(j-i+1<req_len)
            {
               // ans.push_back(-1);
                j++;
            }
            else if(j-i+1==req_len)
            {
                int avg=sum/req_len;
                ans[j-k]=avg;
                sum-=arr[i];
                i++;
                j++;
               // break;
            }
        }
        // cout<<i<<endl;
        return ans;
    }
};