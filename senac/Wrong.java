import java.io.File;
import java.util.*;
import java.text.*;

public class Solved {
    
    static long limit_date_stamp ;
    
    public static void main(String[] args){
        /*// test for list()
        File[] files = list("/home/ubuntu/workspace");
        for(File file: files){
            print(file.getName());
        }
        */
        /*// test for toTimestamp()
        print(toTimestamp("21/09/1987"));
        */
        
        /*//test for file_older_than()
        File test = new File("/home/ubuntu/workspace/LP2/Area.class");
        print(FileOlderThan(test, "13/09/1988"));
        print(FileOlderThan(test, "05/07/2015"));
        */
        
        /*//test for getNewestFileAt
        File newest = getNewestFileAt(new File("/home/ubuntu/workspace"));
        print(newest.getAbsolutePath());
        */
        // old program, unsuitable as of 0724
        // try {
        //     printTheThing(new File(args[0]));
        // } catch(java.lang.ArrayIndexOutOfBoundsException error){
        //     print("Use the root search directory as parameter.");
        // // } catch(java.lang.NullPointerException error){
        // //     print("Invalid file path.");date,
        //             ""
        // }
        
        if(args.length == 2){
            limit_date_stamp  = toTimestamp(args[1]); //in miliseconds
            File dir = new File(args[0]);
            printAllOlderThanLimit(dir);
        } else {
            print(  "Usage:",
                    "program path date",
                    "path is a valid directory path",
                    "date is a valid date formatted as dd/mm/yyyy (eg. 20/01/1967)"
                );
        }
        
    }
    
    public static File printAllOlderThanLimit(File dir){
        File subdirs[]= dir.listFiles();
        for(File file: subdirs){
            if(file.isDirectory()){
                
            } else {
                
            }
        }
        
        
        return dir;
    }
    
    
    
    //fuck this shit
    public static void print(Object... args){
        for(Object stuff: args){
            System.out.println(stuff);
        }
    }
    
    public static File[] list(String path){
        return new File(path).listFiles();
    }
    
    public static long toTimestamp(String date_string){
        long timestamp = 0;
        DateFormat formatter;
        Date date;
        
        try {
            formatter = new SimpleDateFormat("dd/MM/yyyy");
            date = formatter.parse(date_string);
            timestamp = date.getTime();
        } catch(ParseException e){
            System.out.println(e);
        }
        timestamp = timestamp;
        return timestamp;
    }
    
    public static boolean FileOlderThan(File file, String date){
        long timestamp = toTimestamp(date);
        long lastModified = file.lastModified();
        return timestamp > lastModified;
    }
    
    public static File getNewestFileAt(File dir){
        long newest_timestamp = System.currentTimeMillis();
        File newest_file = dir;
        File current_file;
        File dirs[] = dir.listFiles();
        if(dirs != null){
            for(File file : dirs){
                if(file.isDirectory()){
                    current_file = getNewestFileAt(file);  
                } else {
                    current_file = file;
                }
                
                if(current_file.lastModified() < newest_timestamp){
                    newest_timestamp = current_file.lastModified();
                    newest_file = current_file;
                }
            }
        } else {
            print("//skipped inaccessible folder: "+dir.getAbsolutePath());
        }
        return newest_file;
    }
    
    public static void printTheThing(File dir){
        print("Folder         ,    Newest File Date            ,    Newest File Path");
        for(File subdir: dir.listFiles()){
            if(!subdir.isDirectory()){ continue; }
            File newest = getNewestFileAt(subdir);
            Date date = new Date(newest.lastModified()); 
            print(String.format("%-15s",subdir.getName()) + ",    " + date + ",    " + newest.getAbsolutePath());
        }
    }
    
    
}