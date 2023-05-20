class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int a=0;
        int i=0;
        int j=piles.size()-1;
        while(i<=j)
        {
            a+=piles[j-1];
            j=j-2;
            i++;
        }
        return a;
    }
};