//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char>st;
        //stack<char> st = new stack<>();

        int i=0;
        while(x[i]!='\0')
        {
            if(x[i]=='{' || x[i]=='(' || x[i]=='[' )
            {
                st.push(x[i]);
                i++;
            }else if(st.empty()){
                    return false;
                }
            else if(x[i]=='}' || x[i]==')' || x[i]==']')
            {
                if(!st.empty())
                {
                    char c=st.top();
                    if(c=='{' && x[i]=='}')
                    {
                        st.pop();
                        i++;
                    }
                    else if(c=='(' && x[i]==')')
                    {
                        i++;
                        st.pop();
                    }
                    else if(c=='[' && x[i]==']')
                    {
                        i++;
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                
            }
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends