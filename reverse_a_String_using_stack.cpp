//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
char* reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        char *ch=reverse(str,len);
        for(int i=0;i<len;i++)
        {
            cout<<ch[i];
        }
        cout<<endl;
    }
        return 0;
}


// } Driver Code Ends


//return the address of the string
char* reverse(char *S, int len)
{
    //code here
    char*rev;
    stack<char>s;
    int i=0;
    while(i!=len)
    {
        s.push(S[i]);
        i++;
    }
     char *st;
        for(int i=0;i<len;i++){
            S[i]=s.top();
            s.pop();
        }

        return S;

 
    
    
}