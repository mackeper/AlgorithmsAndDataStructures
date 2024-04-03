using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

namespace goodmessages {
    public class Program {

        private static readonly HashSet<char> Vowels = [
            'a', 'e', 'i', 'o', 'u', 'y'
        ];

        internal static void Main(string[] _) {
            var offset = FastIO.NextInt();
            var text = FastIO.ReadLine();
            var n = FastIO.NextInt();

            var chars = text.ToCharArray();
            var badCount = 0;
            for (var i = 0; i < n; i++) {
                Encrypt(chars, offset);
                var (vowels, consonants) = CountVowelsAndConsonants(chars);
                if (vowels >= Math.Ceiling(consonants / 2.0)) {
                    badCount++;
                } else {
                    badCount--;
                }
            }

            if (badCount >= 0) {
                FastIO.WriteLine("Colleague");
            } else {
                FastIO.WriteLine("Boris");
            }
        }

        // Assume only lowercase letters
        private static void Encrypt(char[] text, int offset) {
            for (var i = 0; i < text.Length; i++) {
                var c = text[i];
                var newChar = (char)(c + offset);
                if (newChar <= 'z') {
                } else {
                    newChar = (char)(newChar - 'z' + 'a' - 1);
                }
                text[i] = newChar;
            }
        }

        private static (int vowels, int consonants) CountVowelsAndConsonants(char[] text) {
            var vowels = 0;
            var consonants = 0;
            foreach (var c in text) {
                if (Vowels.Contains(c)) {
                    vowels++;
                } else {
                    consonants++;
                }
            }
            return (vowels, consonants);
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
