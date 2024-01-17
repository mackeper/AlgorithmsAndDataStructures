using System;
using System.Linq;

namespace batterup
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = double.Parse(Console.ReadLine());
            var result = Console.ReadLine().Split().ToList()
                .Select(x => double.Parse(x))
                .Aggregate(
                    Tuple.Create(0, 0.0),
                    (res, x) => x < 0 ? Tuple.Create(res.Item1 + 1, res.Item2) : Tuple.Create(res.Item1, res.Item2 + x));
            Console.WriteLine(result.Item2/(N-result.Item1));
        }
    }
}
