package GraphTraversal;

import Graph.Graph;

/**
 * Created by Bikash on 10/15/2016.
 */

public class BFS extends Graph {

    protected BFS(String fileName){
        super(fileName);
    }

    public static void main(String[] args){
        BFS g = new BFS("sampleData.txt");
        g.printGraph();
    }
}
