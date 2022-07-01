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
        int nge[]=new int[n];
        st.push(n-1);          //  n - array length
        nge[n-1]=n;
        for(int i=n-2;i>=0;i--){
            while(st.size()>0&&a[i]>=a[st.peek()]){
                st.pop();
            }
            if(st.size()==0){
                nge[i]=n;
            }
            else{
                nge[i]=st.peek();
            }
            st.push(i);
        }
        int j=0;
        for(int i=0;i<=n-k;i++){
            if(j<i){
                j=i;
            }
            while(nge[j]<i+k){
                j=nge[j];
            }
            System.out.println(a[j]);
        }

    }
}
