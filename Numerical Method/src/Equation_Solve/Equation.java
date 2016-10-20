package Equation_Solve;

import java.io.File;
import java.net.URL;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by bikash on 10/20/16.
 */
public class Equation {
    ArrayList<String> equations ;
    public Scanner sc;


    public Equation(){

    }

    public Equation(String fileName){
        try{
            URL path = Equation.class.getResource(fileName);
            File file = new File(path.toURI());
            sc = new Scanner(file);

        } catch (Exception e){
            e.printStackTrace();
        }

        equations = new ArrayList<>();

        while (sc.hasNext()){
            String equation = sc.nextLine();
            String formatedEquation = this.formateEquaation(equation);
            equations.add(formatedEquation);
        }

    }

    public String formateEquaation(String equation){
        char[] array = equation.toCharArray();
        String formatedEquation = new String();

        for(int i=0; i<equation.length(); i++){
            if(array[i]!=' '){
                formatedEquation+=array[i];
            }
        }

        int n = formatedEquation.length();
        array = formatedEquation.toCharArray();
        String finalFormatedString = new String();

        for(int i=0; i<n; i++){
            if(array[i]>='a' && array[i]<='z'){
                if(i==0 || (i>0 && (array[i-1]=='+' || array[i-1]=='-'))){

                    finalFormatedString += '1';

                }
            }
            finalFormatedString +=array[i];
        }
        return finalFormatedString;
    }

    public Double [][] getMetrix(int k){
        String [] equation = {equations.get(3*k), equations.get(3*k+1),equations.get(3*k+2)};

        Double [][] a = new Double[3][4];

        for(int i=0; i<3; i++){
            String equ = new String(equations.get(i));
            String numbers = new String();
            char[] array = equ.toCharArray();
            for(int j=0; j<equ.length(); j++){
                if( (array[j]>='a' && array[j]<='z') || array[j]=='=' ){
                    numbers+=' ';
                    continue;
                }
                numbers+=array[j];
            }

            Scanner sc = new Scanner(numbers);
            for(int j=0; j<4; j++){
                String s = sc.next();
                Double d = Double.parseDouble(s);
                a[i][j] = d;
            }

        }


        return a;
    }

    public static void main(String [] args){
        Equation m = new Equation("data.txt");

        for(int i=0; i<m.equations.size(); i++){
            System.out.println(m.equations.get(i));
        }
    }




}
