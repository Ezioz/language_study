/*
 * @Descripttion: 
 * @version: 
 * @Author: ahtoh
 * @Date: 2021-11-10 16:11:38
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-11-16 17:10:25
 */


public class Hello {
    int puppyAge;
    public Hello(String name){
        System.out.println("dog's name : " + name);

    }

    public void setAge(int age){
        puppyAge = age;
    }

    public int getAge(){
        System.out.println("dog's age : " + puppyAge);
        return puppyAge;
    }

    public static void main(String[] args) {
        Hello myPuppy = new Hello("tommy");
        myPuppy.setAge(2);
        myPuppy.getAge();
        System.out.println("value: " + myPuppy.puppyAge);
    }
}
