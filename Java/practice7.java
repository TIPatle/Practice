import java.util.*;
public class practice7 {
    public static void main(String[] args) {
        int row,col;
        Scanner sc = new Scanner(System.in);
        row = sc.nextInt();
        col = sc.nextInt();
        // for(int i =0; i<row; i++){
        //     for(int j = 0; j<col; j++){
        //         System.out.print("* ");
        //     }
        //     System.out.println("");
        // }

        for(int i = 0; i<row*col; i++){
            if(i!=0 && i%col==0){
                System.out.println("");
            }
            System.out.print("* ");
        }  
    }
}
