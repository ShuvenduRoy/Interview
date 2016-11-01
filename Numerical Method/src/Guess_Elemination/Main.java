package Guess_Elemination;

/**
 * Created by bikash on 10/20/16.
 */
public class Main extends Equation {

    Main(){
        super("data.txt");
    }

    public void calculate(){
        Double [][] a = super.getMetrix(0);
        Double [][] u = new Double[3][4];

        u[1-1][1-1] = a[1-1][1-1];
        u[1-1][2-1] = a[1-1][2-1];
        u[1-1][3-1] = a[1-1][3-1];

        u[2-1][1-1] = a[2-1][1-1] / a[1-1][1-1];
        u[2-1][2-1] = a[2-1][2-1] - a[2-1][1-1]*a[1-1][2-1]/a[1-1][1-1];
        u[2-1][3-1] = a[2-1][3-1] - a[2-1][1-1]*a[1-1][3-1]/a[1-1][1-1];

        u[3-1][1-1] = a[3-1][1-1] / a[1-1][1-1];
        u[3-1][2-1] = (a[3-1][2-1] - a[3-1][1-1]*a[1-1][2-1]/a[1-1][1-1])/(a[2-1][2-1] - a[2-1][1-1]*a[1-1][2-1]/a[1-1][1-1]);
        u[3-1][3-1] = a[3-1][3-1] - a[3-1][1-1]*a[1-1][3-1]/a[1-1][1-1] - (a[3-1][2-1]-a[3-1][1-1]/a[1-1][1-1]*a[1-1][2-1])/(a[2-1][2-1]-a[2-1][1-1]/a[1-1][1-1]*a[1-1][2-1])*(a[2-1][3-1]-a[2-1][1-1]/a[1-1][1-1]*a[1-1][3-1]);

        double y1 = a[0][3];
        double y2 = a[1][3] - y1 * u[1][0];
        double y3 = a[2][3] - y1 * u[2][0] - y2 * u[2][1];

        double z = y3/u[2][2];
        double y = ( y2 - z * u[1][2] ) / u[1][1];
        double x = ( y1 - z * u[0][2] - y * u[0][1]) / u[0][0];

        System.out.println("X : " + x);
        System.out.println("Y : " + y);
        System.out.println("Z : " + z);

    }

    public static void main(String [] args){
        Main m = new Main();
        m.calculate();
    }

}
