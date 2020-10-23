/*a java program to fill the details of employee
which includes name,age,address and salary using print_salary methord.
where manager and officer are classe inherited from super class Employee*/
class Employee{
    
    String Name=new String();
    String Age=new String ();
    String address=new String();
    String Salary=new String();
    
    Employee(String a,String b,String c,String d)
    {  
        Name=a;
        Age=b;
        address=c;
        Salary=d;
        
    }
    void display()
    {
        System.out.println("Name is :"+Name);
        System.out.println("age is :"+Age);
        System.out.println("address is :"+address);
    
    }
   void print_salary(){
        System.out.println("the salary of the person :"+Salary);
    }}
 class officer extends Employee{
    
     String department= new String();
     
     officer(String a,String b,String c,String d,String f)
     {
         super(a,b,c,d);
        
         department=f;
    
     }
     
     void display2(){
         super.display();
        
         System.out.println("department :"+department);
         
     }
}
class Manager extends Employee{
    String specialisation=new String();

    Manager(String a,String b,String c,String d,String g )
    {
        super(a,b,c,d);
        specialisation=g;
        
    }
    void display3(){
        super.display();
        System.out.println("specialisation :"+specialisation);
    
    }
}
class Main{
public static void main(String args[]){
 
 officer v=new officer ("mohan","32","xxxxxx","45600","ELECTRICAL");
 v.display2();
 v.print_salary();
 Manager M=new Manager("sherin","46","HJUKIOO","120907","HR");
 M.display3();
 M.print_salary();
    }
}

