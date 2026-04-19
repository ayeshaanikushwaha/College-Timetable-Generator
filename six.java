public class six {
    public static void main(String[] args){
        Employee e1 = new Employee();
        e1.getData("ABC",34);
        e1.printData();
    }
}
class Employee{
    int id;
    String name;

    void getData(String n,int i){
        this.name = n;
        this.id = i;
    }
    void printData(){
        System.out.println("Employee name is: "+name);
        System.out.println("Employee id is: "+id);
    }
}
