package GradeBook;
public class GradeBookTest {
    public static void main(String [] args){
        GradeBook myGradeBook =  new GradeBook("BCC221");

        System.out.printf("Initial course name is: %s\n\n", myGradeBook.getCourseName());
    }
}
