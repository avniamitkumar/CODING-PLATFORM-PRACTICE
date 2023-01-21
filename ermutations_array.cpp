class Solution {
public:
void solve(vector<int>arr,vector<int>&ds,vector<vector<int>>&ans,int freq[])
	{
	    if(ds.size()==arr.size())
	    {
	        ans.push_back(ds);
	        return;
	    }
	    for(int i=0;i<arr.size();i++)
	    {
            if(!freq[i]){
	        ds.push_back(arr[i]);
	        freq[i]=1;
	        solve(arr,ds,ans,freq);
	        freq[i]=0;
	        ds.pop_back();}
	    }
	}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>> ans;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++)
        {
            freq[i]=0;
        }
        solve(nums,ds,ans,freq);
        return ans;

    }
};