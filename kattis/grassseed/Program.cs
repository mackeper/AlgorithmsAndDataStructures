using System;

namespace grassseed
{
    class Program
    {
        static void Main(string[] args)
        {
            var cost = double.Parse(Console.ReadLine());
            var N = Int32.Parse(Console.ReadLine());
            //var lawns = new List<Tuple<int, int>>();
            var total_cost = 0.0;
            for (var i = 0; i < N; i++)
            {
                var line = Console.ReadLine().Split();
                var w = double.Parse(line[0]);
                var h = double.Parse(line[1]);
                total_cost += w*h*cost;
            }
            Console.WriteLine(total_cost);
        }
    }
}