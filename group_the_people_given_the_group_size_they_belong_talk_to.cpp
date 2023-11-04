class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& arr) {
        int n=arr.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({arr[i],i});
        }
        sort(v.begin(),v.end());
        vector<vector<int>>ans;
        int i=0;
        while(i<n)
        {
            int sz=v[i].first;
            vector<int>temp;
            while(i<n && sz--)
            {
                temp.push_back(v[i].second);
                i++;
            }
            ans.push_back(temp);

        }
        return ans;
       
    }
};