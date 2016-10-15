package GraphTraversal;

import Graph.Graph;
import inheritance.Linked_list;

import java.util.Iterator;
import java.util.LinkedList;

/**
 * Created by Bikash on 10/15/2016.
 */

public class BFS extends Graph {

    protected BFS(String fileName){
        super(fileName);
    }

    private void bfs(int s){
        int V = super.V;
        boolean visited[] = new boolean[V];
        //System.out.print(V);

        LinkedList<Integer> queue = new LinkedList<>();
        queue.add(s);
        visited[s] = true;

        while (!queue.isEmpty()){
            s = queue.poll();
            System.out.print(s + " ");

            Iterator<Integer> i = super.adj[s].listIterator();
            while(i.hasNext()){
                int n = i.next();
                if(!visited[n]){
                    visited[n] = true;
                    queue.add(n);
                }
            }
        }

    }

    public static void main(String[] args){
        BFS g = new BFS("sampleData.txt");
        g.bfs(2);
    }
}
