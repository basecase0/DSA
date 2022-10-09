import java.util.*;
public class getMazePathsWithJump {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        ArrayList<String>paths=getMazepathsJump(1,1,n,m);
        System.out.println(paths);
    }

    public static ArrayList<String> getMazepathsJump(int sr,int sc,int dr,int dc){
        if(sr==dr&&sc==dc){
            ArrayList<String> bres=new ArrayList<>();
            bres.add("");
            return bres;
        }
        ArrayList<String>mpaths=new ArrayList<>();

        for(int ms=1;ms<=dc-sc;ms++){
            ArrayList<String>hpaths=getMazepathsJump(sr,sc+ms,dr,dc);
            for(String hpath:hpaths){
                mpaths.add("h"+ms+hpath);
            }
        }
        for(int ms=1;ms<=dr-sr;ms++){
            ArrayList<String>vpaths=getMazepathsJump(sr+ms,sc,dr,dc);
            for(String vpath:vpaths){
                mpaths.add("v"+ms+vpath);
            }
        }
        for(int ms=1;ms<=dc-sc && ms<=dr-sr;ms++){
            ArrayList<String>dpaths=getMazepathsJump(sr+ms,sc+ms,dr,dc);
            for(String dpath:dpaths){
                mpaths.add("d"+ms+dpath);
            }
        }
        return mpaths;
    }
}
