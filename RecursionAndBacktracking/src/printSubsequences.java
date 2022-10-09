import java.util.*;
public class printSubsequences {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String st=sc.next();
//        printss(st,"");
//        printKPC
        String str=sc.next();
        printKPC(str,"");
    }
    public static void printss(String st,String ans){
        if(st.length()==0){
            System.out.println(ans);
            return;
        }
        char ch=st.charAt(0);
        String ros=st.substring(1);
        printss(ros,ans+ch);      // yes
        printss(ros,ans+"");       //no
    }
    static String codes[]={".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};      //KPC
    public static void printKPC(String que,String ans){
        if(que.length()==0){
            System.out.println(ans);
            return;
        }
        char ch=que.charAt(0);
        String ros=que.substring(1);    //faith
        String codech=codes[ch-'0'];
        for(int i=0;i<codech.length();i++){
            char chcodech=codech.charAt(i);
            printKPC(ros,ans+chcodech);     // all characters of the key pressed.
        }
    }
}
