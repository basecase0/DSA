import java.util.*;
public class printMazepaths {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int dr=sc.nextInt();
        int dc=sc.nextInt();
//        printmpaths(1,1,dr,dc,"");
        printmjump(1,1,dr,dc,"");
    }
    public static void printmpaths(int sr,int sc,int dr,int dc,String ans){
        if(sr==dr && sc==dc){   // bc
            System.out.println(ans);
            return;
        }
        if(sr<dr){      // call smart base case normal or call stupid base case smart..
            printmpaths(sr+1,sc,dr,dc,ans+"v");
        }
        if(sc<dc){
            printmpaths(sr,sc+1,dr,dc,ans+"h");
        }
    }

    public static void printmjump(int sr,int sc,int dr,int dc,String ans){
        if(sr==dr && sc==dc){
            System.out.println(ans);
            return;
        }
        for(int i=1;i<=dc-sc;i++){
            printmjump(sr,sc+i,dr,dc,ans+"h"+i);    // sc+i and max dc-sc  ans+h+1,2,...
        }
        for(int ms=1;ms<=dr-sr;ms++){
            printmjump(sr+ms,sc,dr,dc,ans+"v"+ms);
        }
        for(int ms=1;ms<=dr-sr && ms<=dc-sc;ms++){
            printmjump(sr+ms,sc+ms,dr,dc,ans+"d"+ms);
        }
    }
}
