class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxx=0;
        int sum=0;
        for(int i=0;i<gain.size();i++)
        {
            sum+=gain[i];
            maxx=max(maxx,sum);
        }
        return maxx;
    }
};