class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
       int pops=0;
       int n=arr.size();
       int lmax=0;
       for(int i=0;i<n;i++)
       {
           lmax=max(lmax,arr[i]);
           if(lmax==i)
           {
               pops++;
           }
       }
       return pops;
    }
};