using System;
using System.Collections.Generic;
using System.Linq;

namespace chanukah
{
    class Program
    {
        static int ReadInt() => Int32.Parse(Console.ReadLine());
        static List<int> ReadInts() => Console.ReadLine().Split().ToList().Select(x => Int32.Parse(x)).ToList();
        static long ReadLong() => Int64.Parse(Console.ReadLine());
        static List<long> ReadLongs() => Console.ReadLine().Split().ToList().Select(x => Int64.Parse(x)).ToList();
        static void Main(string[] args)
        {
            var N = ReadInt();
            for (var i = 0; i < N; i++)
            {
                var data = ReadInts();
                var candles = Enumerable.Range(1, data[1]).Sum();
                Console.WriteLine($"{data[0]} {candles+data[1]}");
            }
        }
    }
}
