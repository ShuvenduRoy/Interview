package ShortestPath;

import Graph.WeightedGraph;

import java.util.Arrays;

/**
 * Created by root on 10/18/16.
 */
public class Floyd_warshall extends WeightedGraph {

    public Floyd_warshall(String fileName){
        super(fileName);
    }

    public void ShortestPath(){
        int [][] dest = new int[V][V];
        Arrays.fill(dest, matrix);

        for(int i=0; i<V; i++){
            for(int j=0; j<V; i++){
                for(int k=0; k<V; j++){
                    if(dest[i][k]+dest[k][j]<dest[i][j]){
                       dest[i][j] = dest[i][k]+dest[k][j];
                    }
                }
            }
        }

        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                System.out.print(dest[i][j]);
            }
            System.out.println();
        }
    }

    public static void main(String[] args){
        Floyd_warshall g = new Floyd_warshall("weightedGraph.txt");
        g.ShortestPath();
    }
}
