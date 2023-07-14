class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        string temp=" ";

        for(int i=0;i<s.size();i++){
            // If Whitespace found & if temp string is not empty then push temp string in Stack
            if(s[i]==' ' && temp!=" "){
                st.push(temp);
                temp=" ";
            }
            // Else add char to temp string
            else if(s[i]!=' '){
                temp+=s[i];
            }
        }
        // This Condition is for last word i.e. 
        // We will exit from loop without adding last word of string therefore , add last word manually 
        if(temp!=" "){
                    st.push(temp);
            }

        // Storing Words in one string from stack 
        string str="";

        while(!st.empty()){
            str+=st.top();
            st.pop();
        }

        // Removing Whitespaces from starting if exist!

        int index=0;
        while(str[index]==' '){
            index++;
        }

        string Ans="";

        for(int i=index;i<str.size();i++){
            Ans+=str[i];
        }
        return Ans;
    }
};