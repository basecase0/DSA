import java.util.*;
public class printPermutations {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String str=sc.next();
        permutation(str,"");
    }
    public static void permutation(String que,String ans){
        if(que.length()==0){
            System.out.println(ans);
            return;
        }
        for(int i=0;i<que.length();i++){
            char ch=que.charAt(i);
            String qlpart=que.substring(0,i);   // removing ith char from string  0 to i-1
            String qrpart=que.substring(i+1);
            permutation(qlpart+qrpart,ans+ch);
        }
    }
}
