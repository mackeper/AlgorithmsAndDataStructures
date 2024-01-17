using System;
using System.IO;
using System.Text;
using System.Linq;
using System.Collections.Generic;
using System.Runtime.InteropServices;

namespace Parking2
{
    class Program
    {

        static void Main(string[] args)
        {
            var N = FastIO.NextInt();
            while(N-- > 0)
            {
                var S = FastIO.NextInt();
                var l = new List<int>();
                for (var i = 0; i < S; i++)
                    l.Add(FastIO.NextInt());
                FastIO.WriteLine((2*(l.Max() - l.Min())).ToString());
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
            char c = '-';
            while((int)c != 65533 && predicate(c = getchar_unlocked()))
            {
                if ((int)c == 65533 && sb.Length == 0)
                    return null;
                sb.Append(c);
            }
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
