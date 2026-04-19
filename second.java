public class second {
    public static void main(String[] args) {
        //Student object
        Student s1 = new Student();
        s1.Display("ABC", 23);
    }

}

class Student {
    int id;
    String name;
    
    void Display(String n, int i) {
        System.out.println("Student name is " + n);
        System.out.println("Student id is " + i);
    }
}
