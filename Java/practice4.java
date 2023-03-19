import java.util.*;
public class practice4 {
    public static void main(String[] args) {
        int num;
        Scanner sc = new Scanner(System.in);
        num = sc.nextInt();
        if((num&1)==0){
            System.out.println("Even");
        } 
        else{
            System.out.println("Odd");
        }
    }
}
