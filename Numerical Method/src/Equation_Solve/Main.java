package Equation_Solve;

import java.util.Scanner;

/**
 * Created by bikash on 10/20/16.
 */
public class Main extends Equation {

    Main(){
        super("data.txt");
    }

    public void calculate(){
        Double [][] a = super.getMetrix(0);
        for(int i=0; i<3; i++){
            for(int j=0; j<4; j++){
                System.out.println(a[i][j]);
            }
        }

    }

    public static void main(String [] args){
        Main m = new Main();
        m.calculate();
    }

}
