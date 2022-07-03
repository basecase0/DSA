import java.io.*;
import java.util.*;

public class MergeOverlapping {

    public static void main(String[] args) throws Exception {
        // write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] arr = new int[n][2];

        for (int j = 0; j < n; j++) {
            String line = br.readLine();
            arr[j][0] = Integer.parseInt(line.split(" ")[0]);
            arr[j][1] = Integer.parseInt(line.split(" ")[1]);
        }

        mergeOverlappingIntervals(arr);
    }

    public static void mergeOverlappingIntervals(int[][] arr) {
        int n=arr.length;
        // merge overlapping intervals and print in increasing order of start time
        for(int i=0;i<n;i++){
            int max=i;
            for(int j=i+1;j<n;j++){
                if(arr[j][0]<arr[max][0]){
                    max=j;
                }
            }
            int temp=arr[i][0];
            arr[i][0]=arr[max][0];
            arr[max][0]=temp;
            int temp1=arr[i][1];
            arr[i][1]=arr[max][1];
            arr[max][1]=temp1;
        }
        Stack<Integer>merge=new Stack<>();
        for(int i=0;i<n;i++){

        }
    }

}