import java.io.*;
import java.util.*;

public class InfixConversions{

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String exp = br.readLine();
        // code
        Stack<String>pre=new Stack<>();
        Stack<String>post=new Stack<>();
        Stack<Character>optors=new Stack<>();
        for(int i=0;i<exp.length();i++){
            char ch=exp.charAt(i);
            if(ch=='('){
               optors.push(ch);
            }
            else if((ch>='0'&&ch<='9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
                pre.push(ch+"");  // char to string
                post.push(ch+"");
            }
            else if(ch==')'){
                while(optors.peek()!='('){
                    char optor=optors.pop();
                    String v2=pre.pop();
                    String v1=pre.pop();
                    String prev=optor+v1+v2;
                    pre.push(prev);

                    String p2=post.pop();
                    String p1=post.pop();
                    String postp=p1+p2+optor;
                    post.push(postp);
                }
                optors.pop();
            }
            else if(ch=='+'|| ch=='-'||ch=='*'||ch=='/'){
                while(optors.size()>0&&optors.peek()!='('&&precedence(ch)<=precedence(optors.peek())){
                    char optor=optors.pop();
                    String v2=pre.pop();
                    String v1=pre.pop();
                    String prev=optor+v1+v2;
                    pre.push(prev);

                    String p2=post.pop();
                    String p1=post.pop();
                    String postp=p1+p2+optor;
                    post.push(postp);
                }
                optors.push(ch);
            }
        }
        while(optors.size()!=0){
            char optor=optors.pop();
            String v2=pre.pop();
            String v1=pre.pop();
            String prev=optor+v1+v2;
            pre.push(prev);

            String p2=post.pop();
            String p1=post.pop();
            String postp=p1+p2+optor;
            post.push(postp);
        }
        System.out.println(post.peek());
        System.out.println(pre.peek());
        // or  if u want to empty the stack
//        System.out.println(post.pop());
//        System.out.println(pre.pop());
    }
    public static int precedence(char optor){
        if(optor=='+'){
            return 1;
        }
        else if(optor=='-'){
            return 1;
        }
        else if(optor=='*'){
            return 2;
        }
        else{
            return 2;
        }
    }
}