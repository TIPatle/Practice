import java.util.Scanner;
public class practice9 {
    public static void main(String[] args) {
        int row;
        Scanner sc = new Scanner(System.in);
        row = sc.nextInt();
        for(int i = 1; i<=row; i++){
            for(int j = 1; j<=i; j++){
                System.out.print("* ");
            }
            System.out.println();
        }
    }
}
