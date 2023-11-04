class Solution {
public:
     int MAX_WIDTH;
    string getFinalWord(int i, int j, int eachWordSpace, int extraSpace, vector<string>& words) {
        string s;

        for(int k = i; k < j; k++) {
            s += words[k];

            if(k == j-1)
                continue;

            for(int space = 1; space <= eachWordSpace; space++)
                s += " ";

            if(extraSpace > 0) {
                s += " ";
                extraSpace--;
            }
        }

        while(s.length() < MAX_WIDTH) {
            s += " ";
        }
        
        return s;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n     = words.size();
        MAX_WIDTH = maxWidth;
        int i     = 0;
        while(i<n)
        {
            int lc=words[i].size();
            int j=i+1;
            int ss=0;
            while(j<n && ss+lc+words[j].size()+1<=maxWidth)
            {
                lc+=words[j].size();
                j++;
                ss+=1;
            }
            int rs=maxWidth-lc;
           
            int ews=ss==0?0:rs/ss;
            int es=ss==0?0:rs%ss;

             if(j == n) { //Means we are on last line - Left justfied
                ews = 1;
                es    = 0;
            }
             result.push_back(getFinalWord(i, j, ews, es, words));
            i = j;

        }
        return result;
    }
};