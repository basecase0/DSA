import java.util.*;

public class getStairsPath {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        ArrayList<String> paths=getStairsPaths(n);
        System.out.println(paths);
    }
    public static ArrayList<String> getStairsPaths(int n){
        if(n==0){
            ArrayList<String>bc1=new ArrayList<>();
            bc1.add("");
            return bc1;
        }
        else if(n<0){
            ArrayList<String>bc2=new ArrayList<>();
            return bc2;
        }
        ArrayList<String>path1=getStairsPaths(n-1);
        ArrayList<String>path2=getStairsPaths(n-2);
        ArrayList<String>path3=getStairsPaths(n-3);
        ArrayList<String> totalPaths=new ArrayList<>();     // Euler post
        for(String val1:path1){
            totalPaths.add(1+val1);
        }
        for(String val2:path2){
            totalPaths.add(2+val2);
        }
        for(String val3:path3){
            totalPaths.add(3+val3);
        }
        return totalPaths;
    }
}
