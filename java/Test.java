/*
 * @Descripttion: 
 * @version: 
 * @Author: ahtoh
 * @Date: 2021-11-10 16:11:38
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-11-16 17:10:32
 */


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