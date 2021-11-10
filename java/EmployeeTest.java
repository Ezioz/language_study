// import java.io.*;

public class EmployeeTest {
    public static int age = 1;
    public static void main(String[] args) {
        Employee empOne = new Employee("runoob1");
        Employee empTwo = new Employee("runoob2");

        empOne.empAge(26);
        empOne.empDesignation("chengxuyuan");
        empOne.empSalary(10000);
        empOne.printEmployee();

        empTwo.empAge(21);
        empTwo.empDesignation("cainiao");
        empTwo.empSalary(5000);
        empTwo.printEmployee();


    }
    
}
