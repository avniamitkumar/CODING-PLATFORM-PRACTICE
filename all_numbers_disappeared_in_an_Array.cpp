class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& arr) {
        int n=arr.size();
        int i=0;
        while(i<n)
        {
            int c=arr[i]-1;
            if(arr[i]!=arr[c])
            {
                swap(arr[i],arr[c]);
            }
            else
            {
                i++;
            }

        }
        vector<int>ans;
        int k;
        for(k=0;k<n;k++)
        {
            //cout<<arr[k]<<" ";
            if(arr[k]!=k+1)
            {
                ans.push_back(k+1);
            }
        }
        // for(int j=k+1;j<n;j++)
        // {
        //     ans.push_back(j);
        // }
        return ans;
    }
};