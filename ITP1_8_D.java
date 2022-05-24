import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.nextLine();
    String p = sc.nextLine();

    s = s + s.substring(0, p.length() - 1);

    int result = s.indexOf(p);

    System.out.println(result != -1 ? "Yes" : "No");
  }
}