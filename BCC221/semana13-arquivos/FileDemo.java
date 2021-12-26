import java.io.File;
import java.util.Scanner;

public class FileDemo {
    public static void analyzePath(String path){
        File name =  new File(path);
        if(name.exists()){
            System.out.printf("%s%s\n%s\n%s\n%s\n%s%s\n%s%s\n%s%s\n%s%s\n%s%s\n", 
            name.getName(),
            " exists", (name.isFile() ? " is a file" : " is not a file"),
            (name.isDirectory() ? " is a directory" :  "is not a directory"),
            (name.isAbsolute() ? " is absolute path": "is not abs path"),
            "last modified: ", name.lastModified(),
            "length: ", name.length(),
            "path: ", name.getPath(),
            "absolute path: ", name.getAbsolutePath(),
            "parent: ", name.getParent());

            if (name.isDirectory()) {
                String dir[] = name.list();
                System.out.println("\n\nDir contains:\n");

                for (String dirName : dir) {
                    System.out.printf("%s\n", dirName);
                }
            }
        } else {
            System.out.printf("%s %s", path, "does not exist");
        }    
    }

    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter file or dir name: ");
        analyzePath(in.nextLine());
    }
}