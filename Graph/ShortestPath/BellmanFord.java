package ShortestPath;

import Graph.WeightedGraph;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by Bikash on 10/16/2016.
 */
public class BellmanFord extends WeightedGraph{
    public BellmanFord(String fileName){
        super(fileName, 2);
    }

    public void shortestPath(int src){

        int [] distance = new int[V];
        Arrays.fill(distance, Integer.MAX_VALUE);
        distance[src] = 0;

        for(int i=0; i<V-1; i++){
            for(int j=0; j<V; j++){
                Node node = nodes.get(j);

                for(int k=0; k<node.adj.size(); k++){
                    int u = j;
                    int v = node.adj.get(k).dest;
                    int w = node.adj.get(k).weight;

                    if(distance[u]!=Integer.MAX_VALUE && distance[v]>distance[u]+w){
                       distance[v] = distance[u] + w;
                    }
                }
            }
        }

        for(int i=0; i<V; i++){
            System.out.println(i + " -> " + distance[i]);
        }

    }

    public static void main(String [] args){
        BellmanFord g = new BellmanFord("weightedGraph.txt");
        g.shortestPath(0);
    }
}
