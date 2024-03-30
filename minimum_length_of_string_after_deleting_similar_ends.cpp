class Solution {
public:
    int minimumLength(string s) {
        int i=0;
        int j=s.size()-1;
        char prev='$';
        while(i<j)
        {
            if(s[i]==s[j])
            {
                prev=s[i];
                i++;
                j--;

            }
            else if(i<=j && s[i]==prev)
            {
                i++;
            }
            else if(i<=j && s[j]==prev)
            {
                j--;
            }
            else
            {
                return j-i+1;
            }
        }
return (i == j && s[i] == prev) ? 0 : j - i + 1;    }
};