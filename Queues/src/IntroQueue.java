import java.util.*;

public class IntroQueue {
    public static void main(String[] args) {
        System.out.println("hello queues");    // FIFO
        Queue<Integer>que=new ArrayDeque<>();
        que.add(10);
        System.out.println(que);
        que.add(20);
        que.add(30);
        System.out.println(que);
        que.remove();
        System.out.println(que);
        System.out.println("Peek of queue " +que.peek());
        Stack<Integer>st=new Stack<>();
        st.push(10);
        st.push(20);
        st.push(30);
        System.out.println(st);
        System.out.println("Peek of stack "+ st.peek());
    }
}
