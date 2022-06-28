import java.io.*;
import java.util.*;

public class Nextgreaterelement{
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

    public static int[] solve(int[] arr){    // o(n)  time // ngter --> next greater element to right.
        // solve
        int ngetr[]=new int[arr.length];
        Stack<Integer>st=new Stack<>();
        ngetr[arr.length-1]=-1;    // last element always -1.
        st.push(arr[arr.length-1]);   // push it in stack.
        for(int i=arr.length-2;i>=0;i--){
            //  -  ans  +   --> pop(smaller elements)  ,  ans will be the one at peek  , push the element to stack.
            while(st.size()>0 && arr[i]>=st.peek()){
                st.pop();
            }
            if(st.size()==0){     // largest element encountered.
                ngetr[i]=-1;
            }
            else{
                ngetr[i]=st.peek();
            }
            st.push(arr[i]);     // push
        }
        return ngetr;
    }

}
