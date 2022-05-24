import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String str = sc.nextLine();
    int q = sc.nextInt();

    for (int i = 0; i < q; i++) {
      String command = sc.next();

      if (command.equals("print")) {
        int a = sc.nextInt();
        int b = sc.nextInt();
        System.out.println(str.substring(a, b + 1));
      } else if (command.equals("reverse")) {
        int a = sc.nextInt();
        int b = sc.nextInt();
        StringBuilder sb = new StringBuilder(str.substring(a, b + 1));
        sb.reverse();
        str = str.substring(0, a) + sb.toString() + str.substring(b + 1);
      } else if (command.equals("replace")) {
        int a = sc.nextInt();
        int b = sc.nextInt();
        String p = sc.next();
        str = str.substring(0, a) + p + str.substring(b + 1);
      }
    }
  }
}