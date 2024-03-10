
using System;
using System.Collections.Generic;
using System.IO;
using System.Runtime.InteropServices;
using System.Text;

namespace jackpot
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = FastIO.NextUlong();
            while (N-- > 0)
            {
                var wheels = FastIO.NextUlong();
                var p = FastIO.NextUlong();
                while (--wheels > 0)
                    p = lcm(p, FastIO.NextUlong());
                if (p > 1000000000)
                    FastIO.WriteLine("More than a billion.");
                else
                    FastIO.WriteLine(p.ToString());
            }
        }
    }

    public static class FastIO
    {
        [DllImport("libc")] public static extern char getchar_unlocked();
        [DllImport("libc")] public static extern char putchar_unlocked(char c);

        static StringBuilder sb = new StringBuilder();
        public static string Next(Func<char, bool> predicate)
        {
            sb.Clear();
            char c;
            while (predicate(c = getchar_unlocked()))
                sb.Append(c);
            return sb.ToString();
        }

        public static string NextString() => Next(c => { return (int)c != 10 && (int)c != 32; });
        public static int NextInt() => int.Parse(Next(c => { return 48 <= (int)c && (int)c <= 57; }));
        public static uint NextUint() => uint.Parse(Next(c => { return 48 <= (int)c && (int)c <= 57; }));
        public static long NextLong() => long.Parse(Next(c => { return 48 <= (int)c && (int)c <= 57; }));
        public static ulong NextUlong() => ulong.Parse(Next(c => { return 48 <= (int)c && (int)c <= 57; }));
        public static string ReadLine() => Next(c => { return (int)c != 10; });
        public static void WriteLine(string s) { Write(s); putchar_unlocked((char)10); }
        public static void Write(string s) { foreach (var c in s) putchar_unlocked(c); }
    }

    public static class CPMath
    {
        static ulong gcf(ulong a, ulong b)
        {
            while (b != 0)
            {
                ulong temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }
        static ulong lcm(ulong a, ulong b) => (a / gcf(a, b)) * b;
    }
}
