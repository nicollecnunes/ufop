package GradeBook;
public class GradeBook{
    private String courseName;

    // construtor
    public GradeBook(String name){
        setCourseName(name);
    }

    public void setCourseName(String name){
        courseName = name;
    }

    public String getCourseName(){
        return courseName;
    }

    public void displayMessage(){
        System.out.printf("Welcome to the grade book for %s\n!", getCourseName());
    }
}