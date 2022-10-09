import java.io.*;
import java.util.*;

public class getSubsequence {

    public static void main(String[] args) throws Exception {
        Scanner sc=new Scanner(System.in);
        String str=sc.next();
        ArrayList<String> res = gss(str);
        System.out.println(res);
    }

    public static ArrayList<String> gss(String str) {
        if(str.length()==0){
            ArrayList<String>bc=new ArrayList<>();
            bc.add("");     // base case if no string,then to one subsequence i.e. ""
            return bc;
        }
        char ch=str.charAt(0);
        String ros=str.substring(1);    // rest of string --> Faith
        ArrayList<String>rres=gss(ros);
        ArrayList<String>myres=new ArrayList<>();
        for(String st:rres){
            myres.add(""+st);   // not choosing ch and ros
            // myres.add(ch+st);
        }
        for(String st:rres){
            // myres.add(""+st);
            myres.add(ch+st);   // choosing ch + ros.
        }
        return myres;
    }

}