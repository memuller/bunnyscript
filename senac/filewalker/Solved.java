import java.io.File;
import java.util.*;
import java.text.*;

public class Solved {
    
    static String date;
    static long size;
    public static void main(String[] args){
        if(args.length == 2){
            date  = args[1];
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
        if(subdirs != null){
            for(File file: subdirs){
                if(FileOlderThan(file, date)){
                    print(  file.getAbsolutePath() + ", " + 
                            (file.isDirectory() ? "" : toMB(file.length())) + "," + 
                            new SimpleDateFormat("yyyy/MM/dd").format(
                                new Date(file.lastModified())
                            )
                    );
                }
                if(file.isDirectory()){
                    printAllOlderThanLimit(file);
                } 
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
    
    public static float toMB(long bytes){
        return bytes;
        //return (bytes/1024)/1024 ;
    }
    
}