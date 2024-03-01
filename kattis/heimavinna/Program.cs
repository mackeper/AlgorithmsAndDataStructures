using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Collections.Generic;
using System.Runtime.InteropServices;

namespace heimavinna
{

    class Program
    {
        static void Main(string[] args)
        {
            var sum = 0;
            var data = FastIO.ReadLine().Split(';');
            foreach (var d in data)
            {
                if (d.Contains("-"))
                {
                    var i = d.Split('-');
                    sum += int.Parse(i[1]) - int.Parse(i[0]) + 1;
                }
                else
                {
                    sum += 1;
                }
            }
            FastIO.WriteLine(sum.ToString());
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
            while(predicate(c = getchar_unlocked()))
                sb.Append(c);
            return sb.ToString();
        }

        public static string NextString() => Next(c => { return (int)c != 10 && (int)c != 32; });
        public static int NextInt() => int.Parse(Next(c => { return 48 <= (int)c && (int)c <= 57; }));
        public static uint NextUint() => uint.Parse(Next(c => { return 48 <= (int)c && (int)c <= 57; }));
        public static long NextLong() => long.Parse(Next(c => { return 48 <= (int)c && (int)c <= 57; }));
        public static string ReadLine() => Next(c => { return (int)c != 10; });
        public static void WriteLine(string s) { Write(s); putchar_unlocked((char)10); }
        public static void Write(string s) { foreach (var c in s) putchar_unlocked(c); }
    }
}
