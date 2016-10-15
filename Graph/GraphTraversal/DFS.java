package GraphTraversal;

import Graph.Graph;

import java.util.Iterator;

/**
 * Created by Bikash on 10/15/2016.
 */
public class DFS  extends Graph{
    private boolean [] visited;

    private DFS(){
        super();
    }

    private void dfs(int v){
        visited = new boolean[super.V];
        dfsUtil(v);
    }

    private  void dfsUtil(int v){
        visited[v] = true;
        System.out.print(v + " ");

        Iterator<Integer> i = super.adj[v].listIterator();
        while (i.hasNext()){
            int n = i.next();
            if(!visited[n]){
                dfsUtil(n);
            }
        }
    }

    public static void main(String[] args){
        DFS g = new DFS();
        g.dfs(2);
    }
}
