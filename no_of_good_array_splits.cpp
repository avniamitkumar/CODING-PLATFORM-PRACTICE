class Solution {
public:
int MOD=1e9+7;
    int numberOfGoodSubarraySplits(vector<int>& arr) {
        vector<int>a;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i]==1)
            {
                a.push_back(i);
            }
        }
        if(a.size()==0)return 0;
 long long ans = 1;
          for(int i = 1; i < a.size(); i++){
            ans = ((ans%MOD) * (abs(a[i - 1] - a[i])%MOD)) % MOD;
        }
        
        return ans % MOD;}
};