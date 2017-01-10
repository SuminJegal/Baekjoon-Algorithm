/**
 * Created by jegalsumin on 2017. 1. 10..
 */
import java.util.Scanner;

public class Main {
        public static void main(String... args){
            Scanner scanner = new Scanner(System.in);
            int[][] site = new int[scanner.nextInt()][2];

            for (int i = 0; i<site.length; i++){
                site[i][0] = scanner.nextInt();
                site[i][1] = scanner.nextInt();

                if(site[i][0] == 1){
                    System.out.println(site[i][1]);
                }
                else if(site[i][0] == site[i][1]){
                    System.out.println("1");
                }
                else{
                    double result=1;
                    int k=1;
                    if(site[i][1]/2>site[i][0]){
                        for(int j=site[i][1]; j>site[i][1]-site[i][0]; j--){
                            result = result*j;
                            result = result/k;
                            k++;
                        }
                    }else{
                        for(int j=site[i][1]; j>site[i][1]-site[i][0]; j--){
                            result = result*j;
                            result = result/k;
                            k++;
                        }
                    }
                    System.out.println((int)result);
                }
            }
        }
}
