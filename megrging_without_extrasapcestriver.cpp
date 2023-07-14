class Solution {
public:
    void swapIfGreater(vector<int>arr1,vector<int>arr2,int i ,int j)
    {
        if(arr1[i]>arr2[j])
        {
            swap(arr1[i],arr2[j]);
        }

    }


    void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
        int len=n+m;
        
        int gap=(len/2) +(len%2);
        while(gap>0){
        int left=0;
        int right=left+gap;
        //arr1 and arr 2
        if(left <n && right>=n)
        {
                swapIfGreater(arr1,arr2,left,right-n);
        }
        //arr2 and arr 2
        else if(left>=n)
        {
            swapIfGreater(arr1,arr2,left-n,right-n);
        }
        else 
        {
            swapIfGreater(arr1,arr2,left,right);
        
        }
        if(gap==1)break;
        gap=(gap/2)+(gap%2);
        }
    }
};