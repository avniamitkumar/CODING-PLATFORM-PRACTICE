#include <string>
class Solution {
public:
    // const unordered_map<char,int>mp={
    //     {'I',1},
    //     {'V',5},
    //     {'X',10},
    //     {'L',50},
    //     {'C',100},
    //     {'D',500},
    //     {'M',1000}
    // };

    // mp['I']=1;
    // mp['V']=5
    // mp['X']=10;;
    // mp['L']=50;
    // mp['C']=100;
    // mp['D']=500;
    // mp['M']=1000;



    // cout<<mp[s[i]<<endl;
    int romanToInt(string s) {
        int sum=0;
            unordered_map<char,int>mp={
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
    };

        for(int i=0;i<s.size();i++)
        {
           if(s[i]=='V' || s[i]=='L' || s[i]=='D' || s[i]=='M')
           {
               sum+=mp[s[i]];
           }
           else 
           {
               if(s[i]=='I')
               {
                   if(s[i+1]=='V')
                   {
                       sum+=4;
                       i++;
                   }
                   else if(s[i+1]=='X')
                   {
                       sum+=9;
                       i++;
                   }
                   else 
                   {
                       sum+=1;
                   }
               }
               else if(s[i]=='X')
               {
                   if(s[i+1]=='L')
                   {
                       sum+=40;
                       i++;
                   }
                   else if(s[i+1]=='C')
                   {
                       sum+=90;
                       i++;
                   }
                   else 
                   {
                       sum+=10;
                   }
               }
               else if(s[i]=='C')
               {
                   if(s[i+1]=='D')
                   {
                       sum+=400;
                       i++;
                   }
                   else if(s[i+1]=='M')
                   {
                       sum+=900;
                       i++;
                   }
                   else 
                   {
                       sum+=100;
                   }
               }
           }
        }
        return sum;
    }
};