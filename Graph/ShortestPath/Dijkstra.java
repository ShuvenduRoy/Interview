package ShortestPath;

import Graph.WeightedGraph;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by Bikash on 10/16/2016.
 */
public class Dijkstra extends WeightedGraph{
    Dijkstra(String fileName){
        super(fileName,2);
    }

    public int getMinDiscovered(int [] currentMin, boolean[] discovered){
        int mini = Integer.MAX_VALUE;
        int index=0;

        for(int i=0; i<V; i++){
            if(discovered[i]==false && currentMin[i]<mini){
                mini = currentMin[i];
                index = i;
            }
        }
        return index;
    }

    public Map<Node, Integer> shortestPath(int sourceNodeIndex){

        Map<Node, Integer> distance = new HashMap<>();

        int [] currentMin = new int[V];
        Arrays.fill(currentMin, Integer.MAX_VALUE);
        boolean discovered[] = new boolean[V];

        Node node = nodes.get(sourceNodeIndex);
        currentMin[sourceNodeIndex]=0;

        for(int i=0; i<V; i++){
            int index = getMinDiscovered(currentMin, discovered);

            node = nodes.get(index);
            distance.put(node, currentMin[index]);
            discovered[index] = true;
            int parentCost = currentMin[index];

            for(int j=0; j<node.adj.size(); j++){
                int u = index;
                int v = node.adj.get(j).dest;
                int w = node.adj.get(j).weight;

                if(discovered[v]==false && currentMin[v]>parentCost+w){
                    currentMin[v] = parentCost + w;
                }

            }
        }

        return distance;
    }



    public static void main(String[] args){
        Dijkstra g = new Dijkstra("weightedGraph.txt");
        //g.printGraph();
        Map<Node, Integer> distance = g.shortestPath(0);

        for(int i=0; i<g.V; i++){
            Node node = g.nodes.get(i);
            System.out.println(i + " -> " + distance.get(node));
        }
    }
}
