class Solution {
public:
  bool isPalindrome(string& str,int i,int j){
       // int i=0;j=str.size()-1;
        while(i<j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.size();
        bool f=false;
        int i=0;
        int j=n-1;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
            {
                return isPalindrome(s,i+1,j)||isPalindrome(s,i,j-1);
            }
        }
        return true;
    }
};