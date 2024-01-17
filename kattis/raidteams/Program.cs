using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Runtime;
using System.Collections.Generic;
using System.Runtime.InteropServices;

namespace raidteams
{
    class Program
    {
        static void Main(string[] args)
        {
            GCSettings.LatencyMode = GCLatencyMode.LowLatency; // Try to stop GC from cleaning up.
            var firstSet = new SortedSet<Player>(Comparer<Player>.Create((x, y) => x.first.CompareTo(y.first) == 0 ? x.name.CompareTo(y.name) : -x.first.CompareTo(y.first)));
            var secondSet = new SortedSet<Player>(Comparer<Player>.Create((x, y) => x.second.CompareTo(y.second) == 0 ? x.name.CompareTo(y.name) : -x.second.CompareTo(y.second)));
            var thirdSet = new SortedSet<Player>(Comparer<Player>.Create((x, y) => x.third.CompareTo(y.third) == 0 ? x.name.CompareTo(y.name) : -x.third.CompareTo(y.third)));
            var N = FastIO.NextInt();
            for (var i = 0; i < N; i++)
            {
                var player = new Player
                {
                    name = FastIO.NextString(),
                    first = FastIO.NextUint(),
                    second = FastIO.NextUint(),
                    third = FastIO.NextUint()
                };
                firstSet.Add(player);
                secondSet.Add(player);
                thirdSet.Add(player);
            }

            var firstEnumerator = firstSet.GetEnumerator();
            var secondEnumerator = secondSet.GetEnumerator();
            var thirdEnumerator = thirdSet.GetEnumerator();
            var usedPlayers = new HashSet<Player>(N);
            while(N - usedPlayers.Count >= 3)
            {   
                firstEnumerator.MoveNext();
                var first = firstEnumerator.Current;
                while(usedPlayers.Contains(first) && firstEnumerator.MoveNext())
                    first = firstEnumerator.Current;
                usedPlayers.Add(first);

                secondEnumerator.MoveNext();
                var second = secondEnumerator.Current;
                while(usedPlayers.Contains(second) && secondEnumerator.MoveNext())
                    second = secondEnumerator.Current;
                usedPlayers.Add(second);

                thirdEnumerator.MoveNext();
                var third = thirdEnumerator.Current;
                while(usedPlayers.Contains(third) && thirdEnumerator.MoveNext())
                    third = thirdEnumerator.Current;
                usedPlayers.Add(third);

                if (first.name.CompareTo(second.name) > 0)
                    Swap(ref first.name, ref second.name);
                if (first.name.CompareTo(third.name) > 0)
                    Swap(ref first.name, ref third.name);
                if (second.name.CompareTo(third.name) > 0)
                    Swap(ref second.name, ref third.name);
                
                FastIO.WriteLine($"{first.name} {second.name} {third.name}");
            }
            Environment.Exit(0); // Try to stop GC from cleaning up.
        }

        static void Swap<T> (ref T lhs, ref T rhs)
        {
            T temp = lhs;
            lhs = rhs;
            rhs = temp;
        }
    }

    class Player
    {
        public string name;
        public uint first, second, third;
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
        public static void WriteLine(string s) { Write(s); putchar_unlocked((char)10); }
        public static void Write(string s) { foreach (var c in s) putchar_unlocked(c); }
    }
}