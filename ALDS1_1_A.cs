using System;
using System.Text;
using System.Collections.Generic;

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

  public static bool HasNextInt() {
    string token = Peek();
    tokenBuf = token;
    return int.TryParse(token, out _);
  }

  public static int NextInt() {
    string token = Next();
    return int.Parse(token);
  }
}

// Preamble end

class Program {
  static void writeList<T>(List<T> a) {
    for (int i = 0; i < a.Count; ++i) {
      if (i > 0) {
        Console.Write(" ");
      }

      Console.Write(a[i]);
    }

    Console.WriteLine();
  }

  static void insertionSort<T>(List<T> a) where T : IComparable<T> {
    int n = a.Count;

    for (int i = 1; i <= n - 1; ++i) {
      writeList(a);
      T v = a[i];
      int j = i - 1;

      while (j >= 0 && a[j].CompareTo(v) > 0) {
        a[j + 1] = a[j];
        --j;
      }

      a[j + 1] = v;
    }

    writeList(a);
  }

  static void Main(string[] args) {
    int n = ConsoleScanner.NextInt();
    List<int> a = new List<int>();

    for (int i = 0; i < n; i++) {
      a.Add(ConsoleScanner.NextInt());
    }

    insertionSort(a);
  }
}