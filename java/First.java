/*
 * @Descripttion:
 * @version:
 * @Author: ahtoh
 * @Date: 2021-12-10 20:51:14
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-12-13 15:04:07
 */

public class First {

  public static void main(String[] args) {
    double[] myList = new double[10];
    myList[0] = 5.6;
    myList[1] = 4.5;
    myList[2] = 3.3;
    myList[3] = 13.2;
    myList[4] = 4.0;
    myList[5] = 34.33;
    myList[6] = 34.0;
    myList[7] = 45.45;
    myList[8] = 99.993;
    myList[9] = 11123;
    double total = 0;
    for (int i = 0; i < myList.length; i++) {
      total += myList[i];
    }
    System.out.println("总和为 ：" + total);
  }
}
