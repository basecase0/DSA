import java.util.Scanner;

public class Factorial {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int fac=factorial(n);
        System.out.println(fac);
        int logPow=logPower(2,5);
        System.out.println(logPow);
    }
    public static int factorial(int n){
        if(n==1){
            return 1;
        }
        int fn1=factorial(n-1);
        int fac=n*fn1;
        return fac;
    }
    public static int logPower(int x,int n){    // Time complexity: O(log n)
        if(n==0){
            return 1;
        }
        int xpnb2=logPower(x,n/2);
        int xn=xpnb2*xpnb2;
        if(n%2==1){
            xn*=x;
        }
        return xn;
    }
}