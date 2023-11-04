class Solution {
public:
    bool check_collinear( long long x1,  long long y1,  long long x2,  long long y2,  long long x3,  long long y3){
   long long a = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
   if (a == 0)
     return true;
   return false;
}

    int minimumLines(vector<vector<int>>& arr) {
        int l=1;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        if(n==1 || n==2)
        {
            return n-1;
        }
        for(int i=2;i<n;i++)
        {
            if(check_collinear(arr[i-1][0],arr[i-1][1],arr[i-2][0],arr[i-2][1],arr[i][0],arr[i][1]) )
            {
                //prev=true;
            }
            else
            {
                l++;
               // prev=false;
            }
        }

    return l;
    }
};