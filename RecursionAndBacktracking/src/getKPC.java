import java.util.*;
public class getKPC {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String st=sc.next();
        ArrayList<String>kpc=getCombinations(st);   // total KPC= product of no. of char in each digit.
        System.out.println(kpc);
    }
    static String codes[]={".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};
    public static ArrayList<String> getCombinations(String str){
        if(str.length()==0){
            ArrayList<String>bc=new ArrayList<>();
            bc.add("");
            return bc;
        }
        char ch=str.charAt(0);
        String ros=str.substring(1);    // ros-rest of the string.
        ArrayList<String>rres=getCombinations(ros);     // faith
        String chcode=codes[ch-'0'];
        ArrayList<String>mres=new ArrayList<>();
        for(int i=0;i<chcode.length();i++){
            char chcodech=chcode.charAt(i);
            for(String val:rres){
                mres.add(chcodech+val);
            }
        }
        return mres;

    }
}
