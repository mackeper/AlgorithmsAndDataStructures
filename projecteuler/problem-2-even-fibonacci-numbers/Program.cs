using System;
using System.Linq;
using System.Collections.Generic;

namespace problem_2_even_fibonacci_numbers
{
    class Program
    {
        static int fib()
        {
            var (a, b, sum) = (1, 2, 2);
            while (a+b < 4000000)
                (a, b, sum) = (b, a+b, (a+b)%2==0 ? sum+a+b : sum);
            return sum;
        }

        static IEnumerable<long> fibonacci()
        {
            var (a, b) = (1L, 2L);
            while (true) {
                yield return a;
                (a, b) = (b, a+b);
            }
        }

        static void Main(string[] args)
        {
            Console.WriteLine(fib());
            
            // https://stackoverflow.com/questions/15121665/why-cant-i-use-the-following-ienumerablestring
            Func<int, int, int, int, int> fib2 = null;
            fib2 = (n, a, b, res) => n == 0 ? res : fib2(n - 1, b, a + b, n % 2 == 0 ? res : res + a + b);

            long evenSum = fibonacci().TakeWhile(x => x < 4000000L).Where(x => x % 2L == 0L).Sum();
            Console.WriteLine(evenSum);
        }
    }
}
