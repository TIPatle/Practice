import java.util.*;
public class practice8 {
    public static void main(String[] args) {
        int row, col;
        Scanner sc = new Scanner(System.in);
        row = sc.nextInt();
        col = sc.nextInt();
        for(int i=0; i<row;i++){
            for(int j =0; j<col; j++){
                if(i==0||i==(row-1)||j==0||j==(col-1)){
                    System.out.print("* ");
                }
                else{
                    System.out.print("  ");
                }
            }
            System.out.println();
        }
    }
}
