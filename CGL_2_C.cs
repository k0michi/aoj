using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;

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

struct Vector2 {
  public double X;
  public double Y;

  public Vector2(double x, double y) {
    this.X = x;
    this.Y = y;
  }

  public static Vector2 operator +(Vector2 a, Vector2 b) {
    return new Vector2(a.X + b.X, a.Y + b.Y);
  }

  public static Vector2 operator -(Vector2 a, Vector2 b) {
    return new Vector2(a.X - b.X, a.Y - b.Y);
  }

  public static Vector2 operator *(Vector2 a, Vector2 b) {
    return new Vector2(a.X * b.X, a.Y * b.Y);
  }

  public static Vector2 operator *(Vector2 a, double b) {
    return new Vector2(a.X * b, a.Y * b);
  }

  public static Vector2 operator *(double a, Vector2 b) {
    return new Vector2(a * b.X, a * b.Y);
  }

  public static Vector2 operator /(Vector2 a, Vector2 b) {
    return new Vector2(a.X / b.X, a.Y / b.Y);
  }

  public static Vector2 operator /(Vector2 a, double b) {
    return new Vector2(a.X / b, a.Y / b);
  }
}

static class MathHelper {
  public static double Dot(Vector2 a, Vector2 b) {
    return a.X * b.X + a.Y * b.Y;
  }

  public static double Cross(Vector2 a, Vector2 b) {
    return a.X * b.Y - a.Y * b.X;
  }

  public static double Length(Vector2 a) {
    return Math.Sqrt(Dot(a, a));
  }

  public static double LengthSquared(Vector2 a) {
    return Dot(a, a);
  }

  public static Vector2 Project(Vector2 p1, Vector2 p2, Vector2 p) {
    return p1 + Dot(p - p1, p2 - p1) * (p2 - p1) / LengthSquared(p2 - p1);
  }

  public static Vector2 Normalize(Vector2 a) {
    return a / Length(a);
  }
}

struct Segment2 {
  public Vector2 P0;
  public Vector2 P1;

  public Segment2(Vector2 p0, Vector2 p1) {
    P0 = p0;
    P1 = p1;
  }
}

class Program {
  static Vector2 CrossPoint(Segment2 s1, Segment2 s2) {
    Vector2 v2 = s2.P1 - s2.P0;
    double d1 = Math.Abs(MathHelper.Cross(v2, s1.P0 - s2.P0));
    double d2 = Math.Abs(MathHelper.Cross(v2, s1.P1 - s2.P0));
    double t = d1 / (d1 + d2);
    return s1.P0 + t * (s1.P1 - s1.P0);
  }

  static void Main(string[] args) {
    int q = ConsoleScanner.NextInt32();

    for (int i = 0; i < q; ++i) {
      Vector2 p0 = new Vector2(ConsoleScanner.NextInt32(), ConsoleScanner.NextInt32());
      Vector2 p1 = new Vector2(ConsoleScanner.NextInt32(), ConsoleScanner.NextInt32());
      Vector2 p2 = new Vector2(ConsoleScanner.NextInt32(), ConsoleScanner.NextInt32());
      Vector2 p3 = new Vector2(ConsoleScanner.NextInt32(), ConsoleScanner.NextInt32());

      Vector2 result = CrossPoint(new Segment2(p0, p1), new Segment2(p2, p3));
      Console.WriteLine($"{result.X:f8} {result.Y:f8}");
    }
  }
}