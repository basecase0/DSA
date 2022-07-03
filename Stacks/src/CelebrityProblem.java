import java.io.*;
import java.util.*;

public class CelebrityProblem {

    public static void main(String[] args) throws Exception {
        // write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] arr = new int[n][n];

        for (int j = 0; j < n; j++) {
            String line = br.readLine();
            for (int k = 0; k < n; k++) {
                arr[j][k] = line.charAt(k) - '0';
            }
        }

        findCelebrity(arr);
    }

    public static void findCelebrity(int[][] arr) {
        // if a celebrity is there print it''s index (not position), if there is not then print "none"
        Stack < Integer > st = new Stack < > ();
        for (int i = 0; i < arr.length; i++) {
            st.push(i);
        }
        while(st.size()>=2){
            int i=st.pop();
            int j= st.pop();
            if(arr[i][j]==1){
                st.push(j);    // i knows j --> i not a celebrity
            }
            else{
                st.push(i);   // i does not know j --> j not a celebrity
            }
        }
        int pot=st.pop();
        for(int i=0;i<arr.length;i++){
            if(i!=pot){   // i not equal to pot he knows himself is not relevant.
                if(arr[i][pot]==0||arr[pot][i]==1){
                    System.out.println("none");  // someone does not know pot or pot knows someone.
                    return;
                }
            }
        }
        System.out.println(pot);
    }

}