package inheritance;

import java.util.TreeSet;

public class Tree_set {

	public static void main(String[] args) {
		
		Olive lig = new Ligurio();
		Olive kal = new Kalamata();
		Olive pic = new Picholine();
		
		//Keep things sorted
		TreeSet<Olive> set = new TreeSet<>();
		set.add(pic);
		set.add(kal);
		set.add(lig);
		
		//It required olive class to implement the compareable method
		System.out.println(set);
		
	}

}
