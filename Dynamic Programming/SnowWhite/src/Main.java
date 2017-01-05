/**
 * Created by jegalsumin on 2017. 1. 5..
 */
import java.util.Scanner;

public class Main {

    int[] dwarfs;
    Scanner scanner;
    int[] colours;
    int[][] sequenceOfPicture;

    public static void main(String[] args){
        Main m = new Main();
        m.startCheck();
    }

    public Main(){
        scanner = new Scanner(System.in);
        String inputString;
        int i;

        /**
         * input number of dwarfs and colours of hats
         */
        inputString = scanner.nextLine();
        String numOfDwarfs = "";
        String numOfColours = "";
        i=0;
        while(inputString.charAt(i)!=' '){
            numOfDwarfs = numOfDwarfs+inputString.charAt(i);
            i++;
        }
        i++;
        while(i<inputString.length() && inputString.charAt(i)!=' '){
            numOfColours = numOfColours+inputString.charAt(i);
            i++;
        }

        dwarfs = new int[Integer.parseInt(numOfDwarfs)];
        colours = new int[Integer.parseInt(numOfColours)];

        /**
         * input sequence of colours
         */
        inputString = scanner.nextLine();
        i=0;
        int j=0;
        String currentColour = "";
        while(i<inputString.length()){
            if(inputString.charAt(i)!= ' '){
                currentColour = currentColour + inputString.charAt(i);
            }
            else{
                dwarfs[j++] = Integer.parseInt(currentColour);
                currentColour = "";
            }
            i++;
        }
        dwarfs[j] = Integer.parseInt(currentColour);

        /**
         * input number of pictures
         */
        inputString = scanner.nextLine();
        int numOfPictures = Integer.parseInt(inputString);
        sequenceOfPicture = new int[numOfPictures][2];

        /**
         * input sequence of each picture
         */
        i=0;
        while(i<numOfPictures){
            inputString = scanner.nextLine();
            j=0;
            String start = "";
            while(inputString.charAt(j)!=' '){
                start = start + inputString.charAt(j);
                j++;
            }
            String end = "";
            j++;
            while(j<inputString.length() && inputString.charAt(j)!=' '){
                end = end + inputString.charAt(j);
                j++;
            }
            sequenceOfPicture[i][0] = Integer.parseInt(start);
            sequenceOfPicture[i][1] = Integer.parseInt(end);
            i++;
        }
    }

    public void startCheck(){
        for(int i=0; i<sequenceOfPicture.length; i++){

            for(int k=0; k<colours.length; k++){
                colours[k] = 0;
            }

            for(int j=sequenceOfPicture[i][0]; j<=sequenceOfPicture[i][1]; j++){
                colours[dwarfs[j-1]-1]++;
            }
            int checkPhoto = sequenceOfPicture[i][1] - sequenceOfPicture[i][0] + 1;
            checkPhoto = checkPhoto/2;
            boolean isPretty = false;
            for(int k=0; k<colours.length; k++){
                if(colours[k] > checkPhoto){
                    System.out.println("yes "+(k+1));
                    isPretty = true;
                    break;
                }
            }
            if(isPretty == false){
                System.out.println("no");
            }
        }
    }

}
