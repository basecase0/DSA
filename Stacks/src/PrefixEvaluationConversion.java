import java.io.*;
import java.util.*;

public class PrefixEvaluationConversion {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String exp = br.readLine();

        // code
        Stack<Character>optors=new Stack<>();
        Stack<Integer>opnds=new Stack<>();
        Stack<String>infix=new Stack<>();
        Stack<String>postfix=new Stack<>();
        for(int i=exp.length()-1;i>=0;i--){    // Starts from last element .
            char ch=exp.charAt(i);
            if(Character.isDigit(ch)){
                opnds.push(ch-'0');
                infix.push(ch+"");
                postfix.push(ch+"");
            }
            else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
                int v1=opnds.pop();            // Here, v1 will be pop first then v2.
                int v2=opnds.pop();
                int op=operation(v1,v2,ch);
                opnds.push(op);

                String inv1=infix.pop();
                String inv2=infix.pop();
                String inv='('+inv1+ch+inv2+')';  // infix --> (v1 operator v2).
                infix.push(inv);
                                                  // prefix --> operator v1 v2.
                String postv1=postfix.pop();
                String postv2=postfix.pop();
                String postv=postv1+postv2+ch;   // postfix --> v1 v2 operator.
                postfix.push(postv);

            }
        }
        System.out.println(opnds.pop());
        System.out.println(infix.pop());
        System.out.println(postfix.pop());
    }
    public static int operation(int v1,int v2,char optor){
        if(optor=='+'){
            return v1+v2;
        }
        else if(optor=='-'){
            return v1-v2;
        }
        else if(optor=='*'){
            return v1*v2;
        }
        else{
            return v1/v2;
        }
    }
}
