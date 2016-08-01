package file;

import java.nio.file.Path;
import java.nio.file.Paths;

public class PathClass {
	public static void main(String[] args){
		Path path = Paths.get("loremipsun.txt");
		System.out.println(path.toString());
		
	}
}
