using System;
using System.Runtime.InteropServices;
using System.Text;

namespace jackpot {
    public class Program {
        public static void Main(string[] _) {
            var N = FastIO.NextUlong();
            while (N-- > 0) {
                var wheels = FastIO.NextUlong();
                var p = FastIO.NextUlong();
                while (--wheels > 0) {
                    p = CPMath.lcm(p, FastIO.NextUlong());
                }
                if (p > 1000000000) {
                    FastIO.WriteLine("More than a billion.");
                } else {
                    FastIO.WriteLine(p.ToString());
                }

            }
        }
    }

    public static class FastIO {
        [DllImport("libc")] public static extern char getchar_unlocked();
        [DllImport("libc")] public static extern char putchar_unlocked(char c);

        private static readonly StringBuilder sb = new StringBuilder();
        public static string Next(Func<char, bool> predicate) {
            _ = sb.Clear();
            char c;
            while (predicate(c = getchar_unlocked()))
                _ = sb.Append(c);
            return sb.ToString();
        }

        public static string NextString() => Next(c => { return c != 10 && c != 32; });
        public static int NextInt() => int.Parse(Next(c => { return 48 <= c && c <= 57; }));
        public static uint NextUint() => uint.Parse(Next(c => { return 48 <= c && c <= 57; }));
        public static long NextLong() => long.Parse(Next(c => { return 48 <= c && c <= 57; }));
        public static ulong NextUlong() => ulong.Parse(Next(c => { return 48 <= c && c <= 57; }));
        public static string ReadLine() => Next(c => { return c != 10; });
        public static void WriteLine(string s) { Write(s); _ = putchar_unlocked((char)10); }
        public static void Write(string s) { foreach (var c in s) _ = putchar_unlocked(c); }
    }

    public static class CPMath {
        public static ulong gcf(ulong a, ulong b) {
            while (b != 0) {
                var temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }
        public static ulong lcm(ulong a, ulong b) => a / gcf(a, b) * b;
    }
}
