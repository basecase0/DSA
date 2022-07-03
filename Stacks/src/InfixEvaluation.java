import java.io.*;
import java.util.*;

public class InfixEvaluation{

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String exp = br.readLine();
        Stack<Integer>opnds=new Stack<>();     // operands(digits)
        Stack<Character>optors=new Stack<>();    // operators (+,-,*,/)
        for(int i=0;i<exp.length();i++){
            char ch=exp.charAt(i);
            if(ch=='('){
                optors.push(ch);
            }
            else if(Character.isDigit(ch)){   // to check if ch is a digit 0-9.
                opnds.push(ch-'0');  // converts char to int  '0'=48.
            }
            else if(ch==')'){
                while(optors.peek()!='('){
                    char optor=optors.pop();
                    int v2=opnds.pop();    // v2 first then v1
                    int v1=opnds.pop();
                    int opv=operation(v1,v2,optor);
                    opnds.push(opv);
                }
                optors.pop();
            }
            else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
                while(optors.size()>0 && optors.peek()!='(' && precedence(ch)<=precedence(optors.peek())){
                    // ch is wanting higher priority operators to solve first
                    char optor=optors.pop();
                    int v2=opnds.pop();    // v2 first then v1
                    int v1=opnds.pop();
                    int opv=operation(v1,v2,optor);
                    opnds.push(opv);
                }
                // ch is pushing itself now.
                optors.push(ch);
            }
        }
        while(optors.size()!=0){
            char optor=optors.pop();
            int v2=opnds.pop();    // v2 first then v1
            int v1=opnds.pop();
            int opv=operation(v1,v2,optor);
            opnds.push(opv);
        }
        System.out.println(opnds.peek());
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