class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n=arr.size();
       
        int prod=INT_MIN;
        int f=1;
       /// unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
         //   mp[arr[i]]++;
            f*=arr[i];
            if(f>prod)
            {
                prod=f;
            }
            if(f==0)
            {
                f=1;
            }
        }
        f=1;
        for(int i=n-1;i>=0;i--)
        {
         //   mp[arr[i]]++;
            f*=arr[i];
            if(f>prod)
            {
                prod=f;
            }
            if(f==0)
            {
                f=1;
            }
        }
        return prod;
    }
};