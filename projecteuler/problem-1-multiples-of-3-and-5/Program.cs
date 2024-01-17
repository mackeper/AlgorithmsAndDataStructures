using System;

namespace problem_1_multiples_of_3_and_5
{
    class Program
    {

        /// O(nlogn), I think % is log n? or is it n?
        static int solve()
        {
            var sum = 0;
            for (var i = 0; i < 1000; i++)
                if (i % 3 == 0 || i % 5 == 0)
                    sum += i;
            return sum;
        }

        /// O(1), division might not be 1
        static int solve2(int m)
        {
            var amount = 999 / m;
            var sumOfAmounts = ((amount*amount+amount)/2);
            return m * sumOfAmounts;
        }

        static void Main(string[] args)
        {
            Console.WriteLine(solve());
            Console.WriteLine(solve2(3)+solve2(5)-solve2(15));
        }
    }
}
