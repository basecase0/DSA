import java.io.*;
import java.util.*;

public class getKPC {

    public static void main(String[] args) throws Exception {
        Scanner sc=new Scanner(System.in);
        String st=sc.next();    // Keypad numbers
        ArrayList<String> words=getKPC(st);
        System.out.println(words);
    }
    static String codes[]={".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};
    public static ArrayList<String> getKPC(String str) {    // 573
        if(str.length()==0){
            ArrayList<String>bc=new ArrayList<>();
            bc.add("");
            return bc;
        }
        char ch=str.charAt(0);  // 5
        int c=ch-'0';
        String ros=str.substring(1);
        ArrayList<String>rres=getKPC(ros);  // faith    73
        ArrayList<String>mres=new ArrayList<>();
        String codech=codes[c];
        for(int i=0;i<codech.length();i++){
            char chcode=codech.charAt(i);
            for(String val:rres){
                mres.add(chcode+val);
            }
        }
        return mres;
    }

}