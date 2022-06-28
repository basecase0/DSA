import java.io.*;
import java.util.*;

public class LargestAreaHistogram{

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = Integer.parseInt(br.readLine());
        }

        // code
        Stack<Integer>st=new Stack<>();
        int rb[]=new int[n];    // smallest element on right.
        int lb[]=new int[n];    // smallest element on left
        rb[n-1]=n;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 && a[i]<=a[st.peek()]){
                st.pop();    // greater elements get popped.
            }
            if(st.size()==0){
                rb[i]=n;
            }
            else{
                rb[i]=st.peek();
            }
            st.push(i);
        }
        lb[0]=-1;
        st.push(0);
        for(int i=1;i<n;i++){
            while(st.size()>0 && a[i]<=a[st.peek()]){
                st.pop();    // greater elements get popped.
            }
            if(st.size()==0){
                lb[i]=-1;
            }
            else{
                lb[i]=st.peek();
            }
            st.push(i);
        }
        int maxarea=0;
        for(int i=0;i<n;i++){
            int width=rb[i]-lb[i]-1;
            int area=width*a[i];
            if(area>maxarea){
                maxarea=area;
            }
        }
        System.out.println(maxarea);
    }
}
