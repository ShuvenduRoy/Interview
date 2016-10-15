package Graph;

import java.io.*;
import java.net.URL;
import java.util.LinkedList;
import java.util.Scanner;


/**
 * Created by Bikash on 10/15/2016.
 */

public class Graph {
    private int V;                          //Number of vertices
    private LinkedList<Integer> adj[];      //Array of linked list

    //Default Constructor that comes with default data
    protected Graph(){
        V = 4;
        adj = new LinkedList[V];

        for(int i=0; i<V; i++){
            adj[i] = new LinkedList<>();
        }

        addSampleData();
    }

    //Constructor for directed graph
    protected Graph(String fileName){

        addSampleDataFromFile(fileName, 1);

    }

    //Constructor for undirected Graph
    protected Graph(String fileName, int i){

        addSampleDataFromFile(fileName, i);

    }

    protected void makeGraph(int v){
        V = v;
        adj = new LinkedList[v];

        for(int i=0; i<v; i++){
            adj[i] = new LinkedList<>();
        }
    }

    /**
     * u is source and v is destination
     */

    protected void addEdge(int v, int w){
        adj[v].add(w);
    }

    protected void addBothEdge(int v, int w){
        adj[v].add(w);
        adj[w].add(v);
    }


    //Some test data
    protected void addSampleData(){

            addEdge(0, 1);
            addEdge(0, 2);
            addEdge(1, 2);
            addEdge(2, 0);
            addEdge(2, 3);
            addEdge(3, 4);

    }


    //Adding file from current directory
    protected void addSampleDataFromFile(String fileName, int i){
         try{

             URL path = Graph.class.getResource(fileName);
             File file = new File(path.toURI());
             Scanner sc = new Scanner(file);

             int n = sc.nextInt();
             makeGraph(n);


             while(sc.hasNext()){
                 int u = sc.nextInt();
                 int v = sc.nextInt();
                 if (i==1){
                     addEdge(u,v);
                 } else if (i==2){
                     addBothEdge(u,v);
                 }

             }

         } catch (Exception e){
             e.printStackTrace();
         }
    }


    //Method to prind all tha datas of the graph
    protected void printGraph(){
        for(int i=0; i<adj.length; i++){
            System.out.print(i + " :");
            for(int j=0; j<adj[i].size(); j++){
                System.out.print(" "+ adj[i].get(j));
            }
            System.out.println();
        }
    }
}
