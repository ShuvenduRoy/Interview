package inheritance;

import java.util.Collection;
import java.util.Iterator;
import java.util.LinkedList;

public class Linked_list {
	
	public static void main(String[] args){
		LinkedList<Olive> list = new LinkedList<>();
		list.add(new Picholine());
		list.add(new Kalamata());
		list.add(1, new Ligurio());
		
		display(list);
	}
	
	static private void display(Collection<Olive> col){
		System.out.println("List order: ");
		Iterator<Olive> iterator = col.iterator();
		while(iterator.hasNext()){
			Olive olive = (Olive) iterator.next();
			System.out.println(olive.oliveName.toString());
		}
	}

}
