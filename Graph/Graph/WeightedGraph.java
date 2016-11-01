package Graph;

import java.io.*;
import java.net.URL;
import java.util.*;


/**
 * Created by Bikash on 10/15/2016.
 */

public class WeightedGraph {


    protected int V;    //Number of vertices
    protected Map<Integer, Node> nodes = new HashMap<>();
    protected int [][] matrix;

    public class Node{
        public int data;
        public Node parent;
        public int rank;
        public LinkedList<Edge> adj = new LinkedList<>();
    }

    public class Edge{
        public int dest;
        public int weight;

        public Edge(){

        }

        public Edge(int v, int w){
            dest = v;
            weight = w;
        }
    }



    //Default Constructor that comes with default data
    protected WeightedGraph(){
        V = 4;
        for(int i=0; i<V; i++){
            makeNode(i);
        }

        addSampleData();
    }

    //Constructor for directed graph
    protected WeightedGraph(String fileName){

        addSampleDataFromFile(fileName,1);
        makeMatrix();

    }

    protected WeightedGraph(String fileName, int i){

        addSampleDataFromFile(fileName,i);
        makeMatrix();

    }

    protected void makeGraph(int v){
        V = v;

        for(int i=0; i<v; i++){
           makeNode(i);
        }
    }


    public void makeNode(int data){
        Node node = new Node();
        node.data = data;
        node.parent = node;
        node.rank = 0;
        nodes.put(data, node);
    }

    public void makeMatrix(){
        matrix = new int[V][V];

        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                matrix[i][j] = Integer.MAX_VALUE/10;
            }
        }


        for(int u=0; u<V; u++){
            Node node = nodes.get(u);
            for(int j=0; j<node.adj.size(); j++){
                int v = node.adj.get(j).dest;
                int w = node.adj.get(j).weight;

                matrix[u][v] = w;
            }
        }
    }


    //Some test data
    protected void addSampleData(){

        int [] src = {0,0,1,2,2,3};
        int [] dest = {1,2,2,0,3,3};
        int [] weight = {1,1,1,1,1,1};
        int E = 6;

        for(int i=0; i<6; i++){
            Node node = nodes.get(src[i]);
            Edge edge = new Edge(dest[i],weight[i]);
            node.adj.add(edge);
        }
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
                int w = sc.nextInt();

                if(i==1){
                    Node node = nodes.get(u);
                    Edge edge = new Edge(v,w);
                    node.adj.add(edge);
                } else if (i==2){
                    Node node = nodes.get(u);
                    Edge edge = new Edge(v,w);
                    node.adj.add(edge);

                    node = nodes.get(v);
                    edge = new Edge(u,w);
                    node.adj.add(edge);
                }


            }

        } catch (Exception e){
            e.printStackTrace();
        }
    }




    public boolean union(int data1, int data2){
        Node node1 = nodes.get(data1);
        Node node2 = nodes.get(data2);

        Node parent1 = findSet(node1);
        Node parent2 = findSet(node2);

        if(parent1.data == parent2.data){
            return false;
        }

        if(parent1.rank == parent2.rank){
            parent1.rank = parent1.rank +1;
            parent2.parent = parent1;
        } else if (parent1.rank > parent2.rank){
            parent2.parent = parent1;
        } else {
            parent1.parent = parent2;
        }
        return true;
    }

    public Node findSet(Node node){
        Node parent = node.parent;
        if(parent==node){
            return parent;
        }
        node.parent = findSet(node.parent);
        return node.parent;
    }

    public int findSet(int data) {
        return findSet(nodes.get(data)).data;
    }



    //Method to prind all tha datas of the graph
    protected void printGraph(){
        for(int i=0; i<V; i++){
            System.out.print(i + " :");

            Node node = nodes.get(i);
            for(int j=0; j<node.adj.size(); j++){
                System.out.print(" " + node.adj.get(j).dest + " -> " + node.adj.get(j).weight + " , ");
            }

            System.out.println();
        }
    }

    public static void main(String[] args){
        WeightedGraph g = new WeightedGraph("weightedGraph.txt");
        g.printGraph();
    }
}

