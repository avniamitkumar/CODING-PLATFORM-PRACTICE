//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    
   
    string secondSmallest(int S, int D){
        string s="";
        s+="1";
        if(9*D<=S) //if the given sum exceed the maximum possible sum of digits with the given number of digits then it will
        //not be possible to have the 2nd smallest or even the smallest if(S==9*D)
        //therefore checking that first
        {
            return "-1";
        }
        for(int i=0;i<D-1;i++)
        {
            s.push_back('0');
        }
        int temp=1;
        //now made the smallest number possible with given number of digits
        //for example for D=3 the smallest will be 100
        int n=s.size();
        S--;
        //now creating the 1st smallest number
        for(int i=n-1;i>=0;i--)
        {
            if(S>=9)
            {
                s[i]='9';
                S-=9;
            }
            else
            {
                s[i]+=S;
                S=0;
            }
        }
        //now there is a simple observation where you just have to increase the digit adjacent to 9 decrement that 9 to 8
        for(int i=n-1;i>0;i--)
        {
            if(s[i]!=s[i-1])
            {
               
                    s[i]--;
                    s[i-1]++;
                break;
            }
        }
        return s;
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends