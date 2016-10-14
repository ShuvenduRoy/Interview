package LIS;

import java.util.Arrays;

/**
 * Created by Bikash on 10/15/2016.
 */
public class LIS {
    public static int lis(int[] arr, int n){
        int [] lisCount = new int[n];

        Arrays.fill(lisCount, 1);

        int maxLis = 0;
        for(int i=0; i<n; i++){
            for(int j=i ; j<n; j++){
                if(arr[j]>arr[i] && lisCount[j]<lisCount[i]+1){
                    lisCount[j] = lisCount[i]+1;
                    if(lisCount[j]>maxLis){
                        maxLis = lisCount[j];
                    }
                }
            }
        }
        return maxLis;
    }

    public static void main(String [] args){
        int [] arr = { 10, 22, 9, 33, 21, 50, 41, 60};
        int ans = lis(arr, arr.length);
        System.out.println(ans);
    }
}
