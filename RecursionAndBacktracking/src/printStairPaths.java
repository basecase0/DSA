import java.util.*;
public class printStairPaths {
    public static void main(String[] args) throws Exception {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        printPaths(n,"");
    }

    public static void printPaths(int n, String path) {
        if(n==0){
            System.out.println(path);
            return;
        }
        if(n<0){
            return;
        }
        printPaths(n-1,path+"1");
        printPaths(n-2,path+"2");
        printPaths(n-3,path+"3");
    }
}
