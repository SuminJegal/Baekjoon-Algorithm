/**
 * Created by jegalsumin on 2017. 1. 5..
 */
import java.util.*;

public class Main {

    public static void main(String[] args){
        int concentNum;
        Scanner scanner = new Scanner(System.in);
        concentNum = scanner.nextInt();
        scanner.nextLine();

        int i =0;
        int maxPlug=1;
        while(i<concentNum){
            int temp = scanner.nextInt();
            scanner.nextLine();
            maxPlug += temp;
            maxPlug--;
            i++;
        }

        System.out.println(maxPlug);

    }
}
