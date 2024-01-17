using System;
using System.Linq;
using System.Collections.Generic;

namespace problem_3_largest_prime_factor
{

    class PrimeFactor
    {
        private List<bool> isPrime;

        public PrimeFactor(int size)
        {
            isPrime = Enumerable.Repeat(true, size).ToList();
        }

        public bool IsPrime(long value)
        {
            var a = 1;
            while (a < value)
                if (value % a == 0)
                    return false;
            return true;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var p = new PrimeFactor(13195);
            Console.WriteLine("Hello World!");
        }
    }
}
