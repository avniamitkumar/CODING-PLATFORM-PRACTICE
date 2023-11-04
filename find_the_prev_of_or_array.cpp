class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
       vector<int>ans(pref.size(),0);
       ans[0]=pref[0];
       int prevxor=pref[0];
       for(int i=1;i<pref.size();i++)
       {
           ans[i]=prevxor^pref[i];
           prevxor^=ans[i];
       } 
       return ans;
    }
};