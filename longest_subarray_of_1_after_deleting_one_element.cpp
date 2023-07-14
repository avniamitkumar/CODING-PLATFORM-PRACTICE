class Solution {
public:
    int longestSubarray(vector<int>& arr) {
        unordered_map<int,int>mp;
        int i=0;
        int j=0;
        int n=arr.size();
        int ans=0;
        while(j<n)
        {
            mp[arr[j]]++;
            while(mp[0]>1)
            {
                if(arr[i]==0){
                mp[0]--;}
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans-1;

    }
};