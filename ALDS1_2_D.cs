using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;

// Preamble begin

class ConsoleScanner {
  private static int charBuf = -1;
  private static string tokenBuf = null;

  private static int PeekNextChar() {
    if (charBuf == -1) {
      charBuf = Console.Read();
    }

    return charBuf;
  }

  private static int ReadNextChar() {
    if (charBuf != -1) {
      int temp = charBuf;
      charBuf = -1;
      return temp;
    }

    return Console.Read();
  }

  private static string ConsumeBuffer() {
    string result = "";

    if (tokenBuf != null) {
      result += tokenBuf;
      tokenBuf = null;
    }

    if (charBuf != -1) {
      result += charBuf;
      charBuf = -1;
    }

    return result;
  }

  private static void SkipWhitespaces() {
    while (PeekNextChar() != -1 && char.IsWhiteSpace((char)PeekNextChar())) {
      ReadNextChar();
    }
  }

  private static string ReadNext() {
    SkipWhitespaces();
    StringBuilder sb = new StringBuilder();

    if (PeekNextChar() == -1) {
      return null;
    }

    while (true) {
      int next = PeekNextChar();

      if (next == -1) {
        break;
      }

      char nextChar = (char)next;

      if (char.IsWhiteSpace(nextChar)) {
        break;
      }

      ReadNextChar();
      sb.Append(nextChar);
    }

    return sb.ToString();
  }

  public static string Next() {
    if (tokenBuf != null) {
      string temp = tokenBuf;
      tokenBuf = null;
      return temp;
    }

    string token = ReadNext();

    if (token == null) {
      throw new Exception("No token");
    }

    return token;
  }

  private static string Peek() {
    if (tokenBuf == null) {
      tokenBuf = ReadNext();
    }

    return tokenBuf;
  }

  public static bool HasNext() {
    if (tokenBuf != null) {
      return true;
    }

    SkipWhitespaces();
    return PeekNextChar() != -1;
  }

  public static string NextLine() {
    return ConsumeBuffer() + Console.ReadLine();
  }

  public static bool HasNextLine() {
    return PeekNextChar() != -1;
  }

  public static byte NextByte() {
    string token = Next();
    return Byte.Parse(token);
  }

  public static bool HasNextByte() {
    string token = Peek();
    return Byte.TryParse(token, out _);
  }

  public static sbyte NextBSyte() {
    string token = Next();
    return SByte.Parse(token);
  }

  public static bool HasNextSByte() {
    string token = Peek();
    return SByte.TryParse(token, out _);
  }

  public static short NextInt16() {
    string token = Next();
    return Int16.Parse(token);
  }

  public static bool HasNextInt16() {
    string token = Peek();
    return Int16.TryParse(token, out _);
  }

  public static ushort NextUInt16() {
    string token = Next();
    return UInt16.Parse(token);
  }

  public static bool HasNextUInt16() {
    string token = Peek();
    return UInt16.TryParse(token, out _);
  }

  public static int NextInt32() {
    string token = Next();
    return Int32.Parse(token);
  }

  public static bool HasNextInt32() {
    string token = Peek();
    return Int32.TryParse(token, out _);
  }

  public static uint NextUInt32() {
    string token = Next();
    return UInt32.Parse(token);
  }

  public static bool HasNextUInt32() {
    string token = Peek();
    return UInt32.TryParse(token, out _);
  }

  public static long NextInt64() {
    string token = Next();
    return Int64.Parse(token);
  }

  public static bool HasNextInt64() {
    string token = Peek();
    return Int64.TryParse(token, out _);
  }

  public static ulong NextUInt64() {
    string token = Next();
    return UInt64.Parse(token);
  }

  public static bool HasNextUInt64() {
    string token = Peek();
    return UInt64.TryParse(token, out _);
  }

  public static float NextSingle() {
    string token = Next();
    return Single.Parse(token);
  }

  public static bool HasNextSingle() {
    string token = Peek();
    return Single.TryParse(token, out _);
  }

  public static double NextDouble() {
    string token = Next();
    return Double.Parse(token);
  }

  public static bool HasNextDouble() {
    string token = Peek();
    return Double.TryParse(token, out _);
  }
}

// Preamble end

class Card : IComparable<Card>, IEquatable<Card> {
  char suit;
  int value;

  public Card(char suit, int value) {
    this.suit = suit;
    this.value = value;
  }

  public static bool operator ==(Card a, Card b) {
    return a.suit == b.suit && a.value == b.value;
  }

  public static bool operator !=(Card a, Card b) {
    return !(a == b);
  }

  public static Card FromString(string str) {
    return new Card(str[0], int.Parse(str.Substring(1)));
  }

  public override string ToString() {
    return suit.ToString() + value;
  }

  public int CompareTo(Card other) {
    return value - other.value;
  }

  public bool Equals(Card other) {
    return this == other;
  }
}

class Program {
  static int count = 0;

  static void WriteList<T>(List<T> a, char delimiter = ' ') {
    for (int i = 0; i < a.Count; ++i) {
      if (i > 0) {
        Console.Write(delimiter);
      }

      Console.Write(a[i]);
    }

    Console.WriteLine();
  }

  static void InsertionSort<T>(List<T> a, int g) where T : IComparable<T> {
    int n = a.Count;

    for (int i = g; i < n; ++i) {
      T v = a[i];
      int j = i - g;

      while (j >= 0 && a[j].CompareTo(v) > 0) {
        a[j + g] = a[j];
        j -= g;
        ++count;
      }

      a[j + g] = v;
    }
  }

  static void ShellSort<T>(List<T> a) where T : IComparable<T> {
    int n = a.Count;

    List<int> g = new List<int>();

    // https://ja.wikipedia.org/wiki/%E3%82%B7%E3%82%A7%E3%83%AB%E3%82%BD%E3%83%BC%E3%83%88#%E9%96%93%E9%9A%94%E3%81%AE%E6%B1%BA%E3%82%81%E6%96%B9
    for (int h = 1; h < n || h == 1; h = 3 * h + 1) {
      g.Add(h);
    }

    g.Reverse();

    int m = g.Count;
    Console.WriteLine(m);
    WriteList(g);

    count = 0;

    for (int i = 0; i < m; ++i) {
      InsertionSort(a, g[i]);
    }

    Console.WriteLine(count);
  }

  static void Main(string[] args) {
    int n = ConsoleScanner.NextInt32();
    List<int> a = new List<int>();

    for (int i = 0; i < n; ++i) {
      a.Add(ConsoleScanner.NextInt32());
    }

    ShellSort(a);

    WriteList(a, '\n');
  }
}