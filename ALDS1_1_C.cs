using System;
using System.Text;

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
  static bool IsPrimeNumber(int x) {
    if (x == 2) {
      return true;
    }

    if (x < 2 || x % 2 == 0) {
      return false;
    }

    int sqrtX = (int)Math.Sqrt(x);

    for (int i = 3; i <= sqrtX; i += 2) {
      if (x % i == 0) {
        return false;
      }
    }

    return true;
  }

  static void Main(string[] args) {
    int n = ConsoleScanner.NextInt();

    int count = 0;

    for (int i = 0; i < n; ++i) {
      int x = ConsoleScanner.NextInt();

      if (IsPrimeNumber(x)) {
        ++count;
      }
    }

    Console.WriteLine(count);
  }
}