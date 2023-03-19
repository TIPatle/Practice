import java.util.*;

class firstprogram{
    public static void main(String args[]){
        int n = 5;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<=i; j++){
                System.out.print("* ");
            }
            System.out.println();
        }
        int a = 10;
        int b = 56;
        System.out.println(a+b);
        System.out.println(b-a);
        System.out.println(a*b);
        Scanner sc = new Scanner(System.in);
        String name = sc.nextLine();
        System.out.println(name);        
    }
};