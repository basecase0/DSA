import java.util.*;
public class BalancedBrackets {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String str=sc.nextLine();
        Stack<Character>st=new Stack<>();
        for(int i=0;i<str.length();i++){
            char ch=str.charAt(i);
            if(ch=='('||ch=='['||ch=='{'){
                st.push(ch);
            }
            else if(ch==')'){
                boolean val=handleclosing(st,'(');
                if(val==false){
                    System.out.println("false");
                    return;
                }
            }
            else if(ch==']'){
                boolean val=handleclosing(st,'[');
                if(val==false){
                    System.out.println("false");
                    return;
                }
            }
            else if(ch=='}'){
                boolean val=handleclosing(st,'{');
                if(val==false){
                    System.out.println("false");    // one mistake found return.
                    return;
                }
            }
        }
        if(st.size()==0){
            System.out.println("true");
        }
        else{
            System.out.println("false");
        }
    }
    public static boolean handleclosing(Stack <Character>st,char corresopbarc){
        if(st.size()==0){     // closing bracket is present but there is no opening bracket for it.
            return false;
        }
        else if(st.peek()!=corresopbarc){    // bracket mismatch e.g.  ( is closed by ].
            return false;
        }
        else{
            st.pop();
            return true;
        }
    }
}