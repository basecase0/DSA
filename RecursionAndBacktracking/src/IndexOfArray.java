import java.util.Scanner;

public class IndexOfArray {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        int x=sc.nextInt();
        int ans=firstIndex(arr,0,x);
        System.out.println(ans);
        int anslast=LastIndex(arr,0,x);
        System.out.println(anslast);

        int indicesarr[]=allIndices(arr,x,0,0);
        for(int i=0;i<indicesarr.length;i++){
            System.out.print(indicesarr[i]+" ");
        }
    }
    // MAx of array
    public static int maxOfArray(int[] arr, int idx){
        if(idx==arr.length-1){
            return arr[idx];
        }
        int max=maxOfArray(arr,idx+1);
        if(arr[idx]>max){
            return arr[idx];
        }
        else{
            return max;
        }
    }
    // First Index of x.
    public static int firstIndex(int arr[],int idx,int x){
        if(idx==arr.length){
            return -1;
        }
        if(arr[idx]==x){
            return idx;
        }
        else{
            int fiisa=firstIndex(arr,idx+1,x);
            return fiisa;
        }
    }
    //Last Index of x.
    public static int LastIndex(int arr[],int idx,int x){
        if(idx==arr.length){
            return -1;
        }
        int liisa=LastIndex(arr,idx+1,x);   // faith that 1 to end will give Last index or -1.
        if(liisa==-1){  // No occurrence of x
            if(arr[idx]==x){
                return idx;
            }
            else{
                return -1;
            }
        }
        else{   // x found at last return it.
            return liisa;
        }
    }
    // All indices of x in array.
    public static int[] allIndices(int arr[],int x,int idx,int fsf){
        if(idx==arr.length){
            if(fsf==0){
                System.out.println("NO OUTPUT");
            }
            return new int[fsf];
        }
        if(arr[idx]==x){
            int iarr[]=allIndices(arr,x,idx+1,fsf+1);
            iarr[fsf]=idx;
            return iarr;
        }
        else{
            int iarr[]=allIndices(arr,x,idx+1,fsf);
            return iarr;
        }
    }
}
