import java.util.Scanner;


/**
 * Test
 */
public class Test {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("next: ");
        if (scan.hasNext()) {
            String str1 = scan.next();
            System.out.println("shuchu : " + str1);
            
        }
        scan.close();
    }

    
}