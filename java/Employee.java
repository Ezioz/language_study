/*
 * @Descripttion: 
 * @version: 
 * @Author: ahtoh
 * @Date: 2021-11-10 16:11:38
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-11-16 17:09:13
 */
import java.io.*;
public class Employee {
    String name;
    int age;
    String designation;
    double salary;
    public Employee(String name){
        this.name = name;
    }

    public void empAge(int empAge){
        age = empAge;
    }

    public void empDesignation(String empDesig){
        designation = empDesig;
    }

    public void empSalary(double empSalary){
        salary = empSalary;
    }

    public void printEmployee(){
        System.out.println("name :" + name);
        System.out.println("age : " + age);
        System.out.println("zhiwei : " + designation);
        System.out.println("xinshui : " + salary);
    }
}
