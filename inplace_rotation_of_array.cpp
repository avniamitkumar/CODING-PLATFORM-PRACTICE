class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       /*  int n=arr.size();
        vector<int>s(n);
       
        for(int i=0;i<n;i++)
        {
            s[(i+k)%n]=arr[i];
        }
        arr=s;*/
         k=k%nums.size();
        reverse(nums.begin(),nums.begin()+(nums.size()-k));

        reverse(nums.begin()+(nums.size()-k),nums.end());
    
        reverse(nums.begin(),nums.end());
            
    }
};