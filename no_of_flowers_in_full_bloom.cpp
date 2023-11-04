class Solution {
public:
    int BinarySearchless(vector<int>&arr,int time)
    {
        int st=0;
        int end=arr.size()-1;
        int ans=-1;
        while(st<=end)
        {
            int mid=st+(end-st)/2;
            if(arr[mid]==time)
            {
                //return mid;
                end=mid-1;
            }
            else if(arr[mid]>=time)
            {
               // ans=mid;
                end=mid-1;
            }
            else
            {
                ans=mid;
                st=mid+1;
            }
        }
        return ans;
    }
     int BinarySearchgreat(vector<int>&arr,int time)
    {
        int st=0;
        int end=arr.size()-1;
        int ans=end+1;
        while(st<=end)
        {
            int mid=st+(end-st)/2;
            if(arr[mid]==time)
            {
                //ans=mid;
                st=mid+1;
            }
            else if(arr[mid]>time)
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
                //ans=mid;
                st=mid+1;
            }
        }
        return ans;
    }




    vector<int> fullBloomFlowers(vector<vector<int>>& f, vector<int>& p) {
        // vector<int>ans;
        // for(int i=0;i<p.size();i++)
        // {
        //     int a=0;
        //     for(int j=0;j<f.size();j++)
        //     {
        //         if(p[i]>=f[j][0] && p[i]<=f[j][1])
        //         {
        //             a++;
        //         }
        //     }
        //     ans.push_back(a);
        // }
        // return ans;
        vector<int>begin(f.size(),0);
        vector<int>finish(f.size(),0);
        for(int i=0;i<f.size();i++)
        {
            begin[i]=f[i][0];
            finish[i]=f[i][1];
        }
        sort(begin.begin(),begin.end());
        sort(finish.begin(),finish.end());


        vector<int>ans(p.size(),0);
        for(int i=0;i<p.size();i++)
        {
            int less=BinarySearchgreat(begin,p[i]);
            int great=BinarySearchless(finish,p[i]);
            //cout<<less<< " "<<great<<endl;
         //  ans.push_back(less-great-1);
         ans[i]=less-great-1;
        }

        return ans;
    }
};