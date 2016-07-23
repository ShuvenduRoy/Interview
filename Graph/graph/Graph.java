package graph;

public class Graph {
	public class Edge{
		public int src, dest, weight;
		
		public Edge(){
			src=dest=weight=0;
		}
	}
	
	public int V;
	public int E;
	public Edge edge[];
	
	public Graph(int v, int e){
		V=v;
		E=e;
		edge=new Edge[E];
		for(int i=0; i<e; i++)
			edge[i]=new Edge();
	}
	
}
