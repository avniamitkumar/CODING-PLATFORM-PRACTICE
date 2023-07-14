class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n=arr.size();
        int i=1;
        int dup=arr[0];
        for(int i=1;i<n;i++)
        {
            if(arr[i]==dup)arr[i]=1000;
            else dup=arr[i];
        }
       int s=0,e=0;
        while(e<n)
        {
            if(arr[e]==1000)
            {
                e++;
            }
            else
            {
                swap(arr[s],arr[e]);
                s++;
                e++;
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=1000)
            {
                cnt++;
            }
        }
        return cnt;
    }
};