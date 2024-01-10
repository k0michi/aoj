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

class Program {
  static void Main(string[] args) {
    int n = ConsoleScanner.NextInt32();
    LinkedList<int> list = new LinkedList<int>();

    for (int i = 0; i < n; ++i) {
      string command = ConsoleScanner.Next();

      if (command == "insert") {
        int x = ConsoleScanner.NextInt32();
        list.AddFirst(x);
      } else if (command == "delete") {
        int x = ConsoleScanner.NextInt32();
        var found = list.Find(x);

        if (found != null) {
          list.Remove(found);
        }
      } else if (command == "deleteFirst") {
        list.RemoveFirst();
      } else if (command == "deleteLast") {
        list.RemoveLast();
      }
    }

    Console.WriteLine(string.Join(' ', list));
  }
}