double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int i=0,j=0,k=0;
    int c[nums1Size + nums2Size];
    while(i<nums1Size && j<nums2Size)
    {
       if(nums1[i]<nums2[j])
       {
           c[k++]=nums1[i++];
       }
       else if(nums2[j]<nums1[i])
       {
           c[k++]=nums2[j++];
       }
       else
       {
           c[k++]=nums1[i++];
           //j++;
       }
    }
    while(i<nums1Size)
    {
        c[k++]=nums1[i++];
    }
    while(j<nums2Size)
    {
        c[k++]=nums2[j++];
    }
    for(int i=0;i<k;i++)
    {
        printf(" %d  ",c[i]);
    }
    int n=k;
    if(n%2==0)
    {
        int m=n/2;
        int l=(n/2)+1;
        //printf(".%d.",n);
    double sum=c[m-1]+c[l-1];
        return sum/2.0;
    }
    else
    {
        
        return c[((n+1)/2)-1];
    }
    
    return;
}