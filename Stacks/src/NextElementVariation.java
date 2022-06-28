import java.io.*;
import java.util.*;

public class NextElementVariation{
    public static void display(int[] a){
        StringBuilder sb = new StringBuilder();

        for(int val: a){
            sb.append(val + "\n");
        }
        System.out.println(sb);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = Integer.parseInt(br.readLine());
        }

        int[] nge = solve(a);
        display(nge);
    }

    public static int[] solve(int[] arr){    // o(n)  time // ngter --> next greater element to left.
        // solve
        int ngetl[]=new int[arr.length];
        Stack<Integer>st=new Stack<>();
        ngetl[0]=-1;    // first element always -1.
        st.push(arr[0]);   // push it in stack.
        for(int i=1;i<arr.length;i++){
            //  -  ans  +   --> pop(smaller elements)  ,  ans will be the one at peek  , push the element to stack.
            while(st.size()>0 && arr[i]>=st.peek()){
                st.pop();
            }
            if(st.size()==0){     // largest element encountered.
                ngetl[i]=-1;
            }
            else{
                ngetl[i]=st.peek();
            }
            st.push(arr[i]);     // push
        }
        return ngetl;
    }

}
