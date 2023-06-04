//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int n1,int n2,int n3,vector<int> &s1,vector<int> &s2,vector<int> &s3){
        int sum1=0,sum2=0,sum3=0;
        for(int i=0;i<n1;i++)
        {
            sum1+=s1[i];
        }
         for(int i=0;i<n2;i++)
        {
            sum2+=s2[i];
        }
         for(int i=0;i<n3;i++)
        {
            sum3+=s3[i];
        }
       // cout<<sum1<<sum2<<sum3<<endl;
        int a=0,b=0,c=0;
        while(a!=n1 && b!=n2&& c!=n3)
        {
            if(sum1==sum2 && sum2==sum3)return sum1;
            int st=max({sum1,sum2,sum3});
            if(st==sum1){sum1-=s1[a];a++;}
            else if(st==sum2){sum2-=s2[b];b++;}
            else if(st==sum3){sum3-=s3[c];c++;}
            
        }
    return 0;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends