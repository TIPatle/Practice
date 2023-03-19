import java.util.*;
public class practice6 {
    public static void main(String[] args) {
        int choice;
        Scanner sc = new Scanner(System.in);
        choice = sc.nextInt();
        switch(choice){
            case 1 :
                System.out.println("Hello");
                break;
            case 2 :
                System.out.println("Nameste");
                break;
            case 3 :
                System.out.println("Bojunga");
                break;
            default:
                System.out.println("Invalid Input");
        }
    }    
}
