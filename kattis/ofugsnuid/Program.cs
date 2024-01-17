// dotnet publish -c Release -r ubuntu.18.04-x64
using System;
using System.IO;
using System.Text;
using System.Runtime;
using System.Collections.Generic;
using System.Runtime.InteropServices;

public class Program
{
    public static void Main()
    {
        GCSettings.LatencyMode = GCLatencyMode.LowLatency;
        var N = FastIO.NextInt();
        //GC.TryStartNoGCRegion(N*32);
        var l = new int[100000];
        for (var i = 0; i < N; i++)
        {
                l[i] = FastIO.NextInt();
        }
        for (var i = N-1; i >= 0; i--)
        {
                FastIO.WriteLine(l[i].ToString());
        }
    }

    public static class FastIO
    {
        [DllImport("libc")] public static extern char getchar_unlocked();
        [DllImport("libc")] public static extern char putchar_unlocked(char c);

        static StringBuilder sb = new StringBuilder();
        public static string Next(Func<char, bool> predicate)
        {
            sb.Clear(); char c;
            while(predicate(c = getchar_unlocked())) sb.Append(c);
            return sb.ToString();
        }

        public static string NextString() => Next(c => { return (int)c != 10 && (int)c != 32; });
        public static int NextInt() => int.Parse(Next(c => { return 48 <= (int)c && (int)c <= 57; }));
        public static long NextLong() => long.Parse(Next(c => { return 48 <= (int)c && (int)c <= 57; }));
        public static void WriteLine(string s) { Write(s); putchar_unlocked((char)10); }
        public static void Write(string s) { foreach (var c in s) putchar_unlocked(c); }
    }
}