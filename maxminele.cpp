
// User function Template for C

struct pair getMinMax(long long int arr[], long long int n) {
     struct pair minmax;
     int i=0;
     minmax.min=arr[0];
     minmax.max=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>minmax.max)
        {
            minmax.max=arr[i];
        }
        if(arr[i]<minmax.min)
        {
            minmax.min=arr[i];
        }
    }
    return minmax;
}