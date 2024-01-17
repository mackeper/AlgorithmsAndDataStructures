using System;
using System.Collections.Generic;
using System.Linq;

namespace greetings2
{
    class Program
    {
        static int ReadInt() => Int32.Parse(Console.ReadLine());
        static List<int> ReadInts() => Console.ReadLine().Split().ToList().Select(x => Int32.Parse(x)).ToList();
        static long ReadLong() => Int64.Parse(Console.ReadLine());
        static List<long> ReadLongs() => Console.ReadLine().Split().ToList().Select(x => Int64.Parse(x)).ToList();
        static void Main(string[] args)
        {
            var data = Console.ReadLine();
            Console.WriteLine("h"+new string('e', (data.Length-2)*2)+"y");
        }
    }
}
