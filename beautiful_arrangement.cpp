class Solution {
public:

      void solve(vector<int>arr,int ind,int &ans)
    {
        if(ind==arr.size())
        {
            ans++;
            return;
        }
        for(int i=ind;i<arr.size();i++)
        {
             if((arr[i]%(ind+1)==0) || (ind+1)%arr[i]==0){
            swap(arr[i],arr[ind]);
           
            solve(arr,ind+1,ans);
            swap(arr[i],arr[ind]);}
        }
    }
    
    int countArrangement(int n) {
        vector<int>nums;
        for(int i=1;i<=n;i++)
        {
            nums.push_back(i);
        }
          int ans=0;
        solve(nums,0,ans);
        return ans;
    }
};