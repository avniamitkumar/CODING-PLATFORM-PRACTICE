//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    int stoi(string s)
    {
        int n=s.size();
        int i=0;
        if(s[0]=='-')
        {
            i=1;
        }
        int ans=0;
        while(i<n)
        {
            ans=ans*10+(s[i]-'0');
            i++;
        }
      //  cout<<ans<<endl;
        return ans;
    }
    
    
    
    string multiplyStrings(string s1, string s2) {
       //Your code here
     if(s1=="0" || s2== "0")return 0;
     int sign=1;
     if(s1[0]=='-')
     {
         sign*=-1;
         s1=s1.substr(1);
     }
      if(s2[0]=='-')
     {
         sign*=-1;
         s2=s2.substr(1);
     }
     string ans(s1.size()+s2.size(),'0');
     for(int i=s2.size()-1;i>=0;i--)
     {                      
         int carry=0;
         for(int j=s1.size()-1;j>=0;j--)
         {
            int product = (s1[j] -'0') * (s2[i] -'0') + (ans[i + j +1] -'0') + carry;
            carry=product/10;
            ans[i+j+1]=(product%10)+'0';
        }
        ans[i]+=carry;
     }
     int st=0;
     while(st<ans.size()-1 && ans[st]=='0')
     {
         st++;
     }
     string result = ans.substr(st);

     if(sign==-1 && result!="0")
     {
         return "-" +result;
     }
     return result;
       
       
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends