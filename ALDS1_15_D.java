import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;

class Node {
  public Node parent;
  public int freq;
  public char character;
}

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    Map<Character, Node> buildHuffmanTree = buildHuffmanTree(s);
    int length = encode(s, buildHuffmanTree);
    System.out.println(length);
  }

  static int encode(String string, Map<Character, Node> tree) {
    int length = 0;

    for (char c : string.toCharArray()) {
      length += encode(c, tree);
    }

    return length;
  }

  static int encode(char c, Map<Character, Node> tree) {
    int length = 0;
    Node node = tree.get(c);

    if (node.parent == null) {
      return 1;
    }

    while (node.parent != null) {
      node = node.parent;
      length++;
    }

    return length;
  }

  static Map<Character, Node> buildHuffmanTree(String string) {
    Map<Character, Integer> freqMap = new HashMap<>();

    for (char c : string.toCharArray()) {
      freqMap.put(c, freqMap.getOrDefault(c, 0) + 1);
    }

    PriorityQueue<Node> q = new PriorityQueue<>((a, b) -> a.freq - b.freq);
    Map<Character, Node> nodeMap = new HashMap<>();

    for (Map.Entry<Character, Integer> entry : freqMap.entrySet()) {
      Node node = new Node();
      node.freq = entry.getValue();
      node.character = entry.getKey();
      q.add(node);
      nodeMap.put(entry.getKey(), node);
    }

    for (int i = 0; i < nodeMap.size() - 1; i++) {
      Node x = q.poll();
      Node y = q.poll();
      Node z = new Node();
      z.freq = x.freq + y.freq;
      x.parent = z;
      y.parent = z;
      q.add(z);
    }

    return nodeMap;
  }
}