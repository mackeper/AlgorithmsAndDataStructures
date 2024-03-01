using System;

namespace planina
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = Int32.Parse(Console.ReadLine());
            Console.WriteLine((Math.Pow(2,N)+1)*(Math.Pow(2,N)+1));
        }
    }
}
