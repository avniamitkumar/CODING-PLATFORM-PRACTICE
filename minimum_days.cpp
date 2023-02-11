//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
  /*  bool isit(string s)
    {
        int i=0;
        while(s[i]!='\0')
        {
            if(s[i]!='?')
            {
                if(s[i]==s[i+1])
                {
                    return false;
                }
            }
            i++;
        }
        return true;
    }*/
  
  
    int getMinimumDays(int N,string s, vector<int> &p) {
        // code here
       /* int cnt=0;
        int i=0;
      //  cout<<s<<" "<<isit(s)<<endl;
        while(!isit(s))
        {
            s[p[i]]='?';
           // cout<<s<<endl;
            i++;
            cnt++;
        }
       return cnt;*/
       int cnt=0;
       for(int i=0;i<N-1;i++)
       {
            while(s[i+1]==s[i] && s[i]!='?')
            {
                s[p[cnt]]='?';
                cnt++;
            }
       }
       return cnt;
       
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        string S;cin>>S;
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        int res = obj.getMinimumDays(N,S, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends