import java.util.LinkedList;
import java.util.ArrayList;
import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int lanes = sc.nextInt();
    int infoLines = sc.nextInt();
    ArrayList<LinkedList<Integer>> queues = new ArrayList<LinkedList<Integer>>();
    for (int i = 0; i < lanes; i++) queues.add(new LinkedList<Integer>());

    for (int i = 0; i < infoLines; i++) {
      int infoType = sc.nextInt();
      
      if (infoType == 0) { // Finished refueling
        int lane = sc.nextInt();
        int carRefueled = queues.get(lane - 1).remove();
        System.out.println(carRefueled);
      } else if (infoType == 1) { // Car entered
        int car = sc.nextInt();
        LinkedList<Integer> queueToWait = queues.get(0);

        for (int j = 1; j < lanes; j++) {
          if (queues.get(j).size() < queueToWait.size()) {
            queueToWait = queues.get(j);
          }
        }

        queueToWait.add(car);
      }
    }
  }
}