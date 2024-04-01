using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace maximumfix {
    public class Program {
        internal static void Main(string[] _) {
            var n = FastIO.NextInt();
            var rotations = new int[n];

            for (var i = 1; i <= n; i++) {
                var value = FastIO.NextInt();
                var rotation = i - value;
                if (rotation < 0)
                    rotation += n;
                rotations[rotation]++;
            }

            var maxFix = 0;
            var maxRotations = 0;
            foreach (var rotation in rotations) {
                if (rotation.Value > maxFix) {
                    maxFix = rotation.Value;
                    maxRotations = rotation.Key;
                } else if (rotation.Value == maxFix && rotation.Key < maxRotations) {
                    maxRotations = rotation.Key;
                }
            }

            FastIO.WriteLine($"{maxRotations} {maxFix}");
        }

        private static class FastIO {
            [DllImport("libc")] internal static extern char getchar_unlocked();
            [DllImport("libc")] internal static extern char putchar_unlocked(char c);

            private static readonly StringBuilder sb = new();
            public static string Next(Func<char, bool> predicate) {
                _ = sb.Clear();
                char c;
                while (predicate(c = getchar_unlocked()))
                    _ = sb.Append(c);
                return sb.ToString();
            }

            public static string NextString() => Next(c => { return c is not (char)10 and not (char)32; });
            public static int NextInt() => int.Parse(Next(c => { return c is >= (char)48 and <= (char)57; }));
            public static uint NextUint() => uint.Parse(Next(c => { return c is >= (char)48 and <= (char)57; }));
            public static long NextLong() => long.Parse(Next(c => { return c is >= (char)48 and <= (char)57; }));
            public static ulong NextUlong() => ulong.Parse(Next(c => { return c is >= (char)48 and <= (char)57; }));
            public static string ReadLine() => Next(c => { return c != 10; });
            public static void WriteLine(string s) { Write(s); _ = putchar_unlocked((char)10); }
            public static void Write(string s) { foreach (var c in s) _ = putchar_unlocked(c); }
        }

        private static class CPMath {
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
}
