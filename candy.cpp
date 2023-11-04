class Solution {
public:
    int candy(vector<int>& r) {
        //int c=r.size();
        int n=r.size();
        vector<int>arr(n,1);
        for(int i=1;i<n;i++)
        {
          if(r[i]>r[i-1])
          {
            arr[i]=arr[i-1]+1;
          }
        }
         for(int i=n-2;i>=0;i--)
        {
          if(r[i]>r[i+1])
          {
           if(arr[i]<=arr[i+1])
           {
             arr[i]=arr[i+1]+1;
           }
          }
        }
      return accumulate(arr.begin(),arr.end(),0);




    }
};