//{ Driver Code Starts
// Initial Template for Java

import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;

class GFG {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            String str1 = sc.next();
            String str2 = sc.next();

            Solution obj = new Solution();
            String ans = obj.betterString(str1, str2);
            System.out.println(ans);
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {

    public static String betterString(String str1, String str2) {

        // Code here

        List<String> ans1 = new ArrayList<>();

        helper(str1,"",0,ans1);

        

        List<String> ans2 = new ArrayList<>();

        helper(str2,"",0,ans2);

 

        if(ans1.size() >= ans2.size()){

            return str1;

        }else{

            return str2;

        }

    }

    

    public static boolean unique(String tempAns , List<String> ll){

        for(String s : ll){

            if(s.equals(tempAns)) return false;

        }

        return true;

    }

    

    public static void helper(String s, String tempAns, int index, List<String> ll) {

    

        if (s.length() == index) {

            if (tempAns.isEmpty()) {

                return; // when all elements choose not to include then we simply return

            }

            if(unique(tempAns,ll)){

                ll.add(tempAns);

                return;

            }

            

            return;

        }

        helper(s,tempAns+s.charAt(index),index+1,ll); // including

        helper(s,tempAns,index+1,ll); // not including

    }

}

 