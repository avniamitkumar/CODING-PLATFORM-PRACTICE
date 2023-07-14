class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& arr) {
        int i=0;
        int j=0;
        int n=arr.size();
        int maxlen=INT_MIN;
        int len=0;
        for(int j=0;j<n;j++)
        {
            while(arr[j]==0 && i<=j)
            {
                i++;
            }
            len=max(len,j-i+1);
        }
        return len;
    }
};