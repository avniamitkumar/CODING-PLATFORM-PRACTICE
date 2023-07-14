class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int ans=0;
        for(int i=0;i<32;i++)
        {
            int temp=(1<<i);
            int ones=0;
            for(int &a:arr)
            {
                if((a&temp)==0)
                {

                }
                else
                {
                    ones++;
                }
               
            }
             if(ones%3==1)
                {
                    ans=ans|temp;
                }

        }
        return ans;
    }
};