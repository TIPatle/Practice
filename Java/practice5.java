import java.util.*;
public class practice5 {
    public static void main(String[] args) {
        int a,b;
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();
        if(a==b){
            System.out.println("Equal");
        }
        else if(a>b){
            System.out.println("Greater");
        }
        else{
            System.out.println("Lesser");
        }
    }
}
