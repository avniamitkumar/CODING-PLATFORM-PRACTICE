class Solution {
public:
    int minMoves(vector<int>& arr) {
      int mini=INT_MAX;
      int s=0;
      for(int i=0;i<arr.size();i++)
      {
          mini=min(mini,arr[i]);
          s+=arr[i];
      }
        return s-(mini*arr.size());
    }
};