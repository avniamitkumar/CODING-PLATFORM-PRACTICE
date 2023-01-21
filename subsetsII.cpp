class Solution {
public:
void solve(vector<int>arr,vector<int >ds,vector<vector<int>>&ans,int ind,int n)
  {
      if(ind==n)
      {
          ans.push_back(ds);
          return;
      }
      int j=ind;
      while(j<arr.size()-1 && arr[j] == arr[j+1])
            // when ignoring current, ignore all others equivalent to current
            j++;
     // ds.push_back(arr[ind]);
      solve(arr,ds,ans,j+1,n);
      ds.push_back(arr[ind]);
      solve(arr,ds,ans,ind+1,n);
  }

    vector<vector<int>> subsetsWithDup(vector<int>& c) {
       set<int>s;
        for(auto it:c)s.insert(it);
        vector<int>L;
        for(auto it:s){L.push_back(it);}
        vector<vector<int>> ans;
        int n=L.size();
        vector<int>ds;
        //vector<vector<int>>ans;
        sort(c.begin(),c.end());
        solve(c,ds,ans,0,c.size());
         
        return ans;
    }
};