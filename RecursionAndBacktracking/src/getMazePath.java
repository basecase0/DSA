import java.io.*;
import java.util.*;

public class getMazePath {

    public static void main(String[] args) throws Exception {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        ArrayList<String>mazepaths=getMazePaths(1,1,n,m);
        System.out.println(mazepaths);      // only h or v at once.
    }

    // sr - source row
    // sc - source column
    // dr - destination row
    // dc - destination column
    public static ArrayList<String> getMazePaths(int sr, int sc, int dr, int dc) {
        if(sr==dr && sc==dc){
            ArrayList<String> bres=new ArrayList<>();
            bres.add("");
            return bres;
        }
        ArrayList<String>hpaths=new ArrayList<>();
        ArrayList<String>vpaths=new ArrayList<>();
        if(sc<dc){          // call only if condition i.e. if inside matrix
            hpaths=getMazePaths(sr,1+sc,dr,dc);
        }
        if(sr<dr){
            vpaths=getMazePaths(1+sr,sc,dr,dc);
        }
        ArrayList<String>paths=new ArrayList<>();
        for(String hpath:hpaths){
            paths.add("h"+hpath);
        }
        for(String vpath:vpaths){
            paths.add("v"+vpath);
        }
        return paths;
    }

}