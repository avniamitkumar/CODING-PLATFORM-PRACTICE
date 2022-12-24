class Solution {
public:
    vector<int> searchRange(vector<int>& v, int x) {
       int st=0;
        int end=v.size()-1;
        int f=-1,l=-1;
        vector <int>my;
        while(st<=end)
        {
            int mid=st + ((end-st)/2);
            if(v[mid]==x)
            {
                end=mid-1;
                f=mid;
            }
            else if(x<v[mid])
            {
                end=mid-1;
            }
            else
            {
                st=mid+1;
            }
        }
        st=0,end=v.size()-1;
         while(st<=end)
        {
            int mid=st + ((end-st)/2);
            if(v[mid]==x)
            {
                l=mid;
                st=mid+1;
                
            }
            else if(x<v[mid])
            {
                end=mid-1;
            }
            else
            {
                st=mid+1;
            }
        }
        my.push_back(f);
        my.push_back(l);
        return my;
    }  
};