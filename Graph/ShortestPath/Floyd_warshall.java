package ShortestPath;

import Graph.WeightedGraph;

import java.util.Arrays;

/**
 * Created by root on 10/18/16.
 */
public class Floyd_warshall extends WeightedGraph {

    public Floyd_warshall(String fileName){
        super(fileName,2);
    }

    public void ShortestPath(){
        int [][] dest = new int[V][V];


        //Arrays.fill(dest, matrix);
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                dest[i][j] = matrix[i][j];

            }
        }


        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                for(int k=0; k<V; k++){
                    if(dest[i][k]+dest[k][j]<dest[i][j]){
                       dest[i][j] = dest[i][k]+dest[k][j];
                    }
                }
            }
        }

        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(dest[i][j]>=Integer.MAX_VALUE/10){
                    System.out.print("INF ");
                }else {
                    System.out.print(String.format("%-4s",dest[i][j]));
                }

            }
            System.out.println();
        }
    }

    public static void main(String[] args){
        Floyd_warshall g = new Floyd_warshall("weightedGraph.txt");
        g.ShortestPath();
    }
}
