class Solution {
public:
 
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
          std::sort(pairs.begin(), pairs.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });//sort(pairs.begin(),pairs.end());
        int prev=0;
        int res=1;
        for(int i=1;i<n;i++)
        {
            if(pairs[prev][1]<pairs[i][0])
            {
                prev=i;res++;
            }
        }
        return res;
    }
};