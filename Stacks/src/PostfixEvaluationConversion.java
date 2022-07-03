import java.io.*;
import java.util.*;

public class PostfixEvaluationConversion {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String exp = br.readLine();

        // code
        Stack<Integer>opnds=new Stack<>();   // value
        Stack<Character>optors=new Stack<>();
        Stack<String>infix=new Stack<>();
        Stack<String>prefix=new Stack<>();
        for(int i=0;i<exp.length();i++){
            char ch=exp.charAt(i);
            if(Character.isDigit(ch)){
                opnds.push(ch-'0');
                infix.push(ch+"");
                prefix.push(ch+"");
            }
            else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
                int v2=opnds.pop();
                int v1=opnds.pop();
                int op=operation(v1,v2,ch);
                opnds.push(op);

                String inv2=infix.pop();
                String inv1=infix.pop();
                String infv='('+inv1+ch+inv2+')';
                infix.push(infv);

                String prev2=prefix.pop();
                String prev1=prefix.pop();
                String prev=ch+prev1+prev2;
                prefix.push(prev);
            }
        }
        System.out.println(opnds.pop());
        System.out.println(infix.pop());
        System.out.println(prefix.pop());
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