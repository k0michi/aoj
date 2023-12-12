import java.math.BigInteger;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    try (Scanner sc = new Scanner(System.in)) {
      BigInteger a = new BigInteger(sc.next());
      BigInteger b = new BigInteger(sc.next());

      BigInteger result = a.add(b);

      System.out.println(result);
    }
  }
}