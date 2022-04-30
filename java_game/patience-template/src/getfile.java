import java.io.File;
import java.nio.file.Path;
import java.nio.file.FileSystems;
import java.util.ArrayList;
public class getfile {
    
   public ArrayList<String> getpath(){
        ArrayList<String> cards = new ArrayList<String>();
        
        Path path = FileSystems.getDefault().getPath("").toAbsolutePath();
        System.out.println(path + "/cards");
        File folder = new File("/Users/erick/Desktop/java_game/patience-template/src/cards");        
        File[] listOfFiles = folder.listFiles();
        for (int i = 0; i < listOfFiles.length; i++) {
            if (listOfFiles[i].isFile()) {
                cards.add(listOfFiles[i].getName());
              ///  System.out.println("File " + listOfFiles[i].getName());
            } //else if (listOfFiles[i].isDirectory()) {
               // System.out.println("Directory " + listOfFiles[i].getName());
            //}
        }
        return cards;
    }
}
