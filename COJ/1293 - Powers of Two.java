/**
 * Read in N
 * Print 2 ^ N
 */
import java.math.BigInteger;
import java.util.Scanner;


public class Main {
   public static void main(String[] args){
       Scanner in = new Scanner(System.in);
       int N = in.nextInt();
       System.out.println(new BigInteger("2").pow(N));
   }
}
