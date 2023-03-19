//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    //int arr[]={1,2,3,4,5,6,7,8,9};
    



    string smallestNumber(int s, int d){
        // code here 
        
        if(s==0){
            if(d==1){
            return "0";
            }
            else{
                return "-1";
            }
        }
        if(s>9*d){
            return "-1";
        }else{
        string st="";
        for(int i=1;i<d;i++){
            if(s>9)
            {
                s-=9;
                st+="9";
                //s=s-9;
                
            }
            else
            {
                st+=to_string(s-1);
                s=1;
            }
            
        }
        st += to_string(s);
            reverse(st.begin(),st.end());
            return st;
       
        }
         
        
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
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends