class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i=0;
        int j=0;
        int f=0;
        int t=0;
        int ans=0;
        while(j<answerKey.size())
        {
            if(answerKey[j]=='F')
            {
                f++;
            }
            else
            {
                t++;
            }

            while(min(f,t)>k)
            {
                if(answerKey[i]=='F')
                {
                    f--;
                }
                else
                {
                    t--;
                }
                i++;
            }
            ans=max(ans,f+t);
            j++;
        }
        return ans;
    }
};