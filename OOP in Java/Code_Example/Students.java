class Student
{
    private String name;
    private double CGPA;
    private String subjects;
    private String email;

    public Student() 
    {
        this("tusher", 4.00, "CSE", "www.tushar@gmail.com");
    }

    public Student(String n, double cg, String sub, String em)
    {
        name = n;
        CGPA = cg;
        subjects = sub;
        email = em;
    }

    public void display()
    {
        System.out.println("Name: " + name);
        System.out.println("CGPA: " + CGPA);
        System.out.println("Email: " + email);
        System.out.println("Subjects: " + subjects);
    }

    void setValues(String n, String em)
    {
        name = n;
        email = em;
    }

    void setSubjects(String sub)
    {
        subjects = sub;
    }

    void setCGPA(double cg)
    {
        CGPA = cg;
    }

    String getName()
    {
        return name;
    }

    double getCGPA()
    {
        return CGPA;
    }

    String getValues()
    {
        return email + " " + subjects;
    }
}




public class Students
{
    public static void main(String[] args)
    {
        Student s1 = new Student("Mahir Faysal Tushar", 3.87, "CSE", "www.mahirfaysaltushar@gmail.com");
        s1.getCGPA();
        s1.getValues();
        s1.getName();
        s1.setSubjects("CSE");
        s1.setValues("Mahir Faysal Tusher","www.mahirfasaltushar@gmail.com");
        s1.setCGPA(3.87);
        s1.display();


        Student s2 = new Student("Kamal islam", 4.00, "CSE", "www.kamal@gmail.com");
        s2.getCGPA();
        s2.getValues();
        s2.getName();
        s2.setSubjects("CSE");
        s2.setValues("Kamal islam","www.kamal@gmail.com");
        s2.setCGPA(4.00);
        s2.display();
        
    }
}


