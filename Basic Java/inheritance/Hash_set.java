package inheritance;

import java.util.HashSet;

public class Hash_set {

	public static void main(String[] args) {
		
		Olive lig = new Ligurio();
		Olive kal = new Kalamata();
		Olive pic = new Picholine();
		
		//Hash set
		//Set keeps one thing once even if we add it again it will be ignored
		HashSet<Olive> set = new HashSet<>();
		set.add(lig);
		set.add(kal);
		set.add(pic);
		System.out.println("There are "+set.size()); // 3
		set.add(kal);
		System.out.println("There are "+set.size()); // 3
		//null pointer can be added
		set.add(null);
		System.out.println("There are "+set.size()); // 4
		
		
	}

}
