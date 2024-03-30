class Solution {
public:
    long long solve(int ind)
    {
        if(ind==0)
        {
            return 1;
        }
        // if(ind==1){ return 10; } 
        long long mid=1;
        for(int i=0;i<ind;i++)
        {
            if(i==0 || i==1)
            {
                mid*=9;
            }
            else
            {
                mid*=(10-i);
            }
        }
        cout<<mid<<endl;
        return mid + solve(ind-1);
    }
    int countNumbersWithUniqueDigits(int n) {
        return solve(n);
    }
};