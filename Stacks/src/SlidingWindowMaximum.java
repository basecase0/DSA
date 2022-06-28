import java.io.*;
import java.util.*;

public class SlidingWindowMaximum{


    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = Integer.parseInt(br.readLine());
        }
        int k = Integer.parseInt(br.readLine());

        // code
        Stack<Integer>st=new Stack<>();
        int swmax[]=new int[n];
        //ngetr[n-1]=-1;
        st.push(n-1);
        for(int i=0;i<n-3;i++){
            int j=i;
            while(st.size()>0&&a[i]>a[st.peek()]){
                st.pop();
            }
            if(st.size()==0){
                j=-1;
            }
            else{
                j=a[st.peek()];
            }
            if(st.peek()>i+k-1){
                swmax[i]=a[i];
            }
            else{

            }
            st.push(a[i]);
        }
    }
}
