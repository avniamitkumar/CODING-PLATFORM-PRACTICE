class Solution {
public:
    void rotate(vector<int>& arr, int k) {
         int n=arr.size();
        vector<int>s(n);
       
        for(int i=0;i<n;i++)
        {
            s[(i+k)%n]=arr[i];
        }
        arr=s;
    }
};