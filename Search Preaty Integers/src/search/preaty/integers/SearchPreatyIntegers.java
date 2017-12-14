package search.preaty.integers;

import java.util.Arrays;
import java.util.Scanner;

public class SearchPreatyIntegers {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        int n, m;
        int[] firstList, secondList;
        n = input.nextInt();
        m = input.nextInt();

        firstList = new int[n];
        secondList = new int[m];

        for(int i = 0; i < n; i++){
            firstList[i] = input.nextInt();
        }

        for(int i = 0; i < m; i++){
            secondList[i] = input.nextInt();
        }

        Arrays.sort(firstList);
        Arrays.sort(secondList);


        for(int i = 0 ; i < n;i++){
          for(int j = 0; j < m; j++){
            if(firstList[i] == secondList[j]){
              System.out.print(firstList[i]);
              return;
            }
          }
        }


        int firstMin = 9;
        int secondMin = 9;

        for (int i = 0; i < firstList.length; i++) {
            if (firstMin > firstList[i]) {
                firstMin = firstList[i];
            }
        }

        for (int i = 0; i < secondList.length; i++) {
            if (secondMin > secondList[i]) {
                secondMin = secondList[i];
            }
        }

        if (firstMin > secondMin) {
            int num = firstMin + 10 * secondMin;
            System.out.print(num);
        } else {
            int num = firstMin * 10 + secondMin;
            System.out.print(num);
        }

    }

}
