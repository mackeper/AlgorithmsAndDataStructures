using System;
using System.Linq;

namespace magictrick
{
    class Program
    {
        static void Main(string[] args)
        {
            var cards = Console.ReadLine().ToCharArray().ToList();
            var uniqueCards = cards.Distinct().ToList();
            if (cards.Count == uniqueCards.Count)
                System.Console.WriteLine(1);
            else
                System.Console.WriteLine(0);
        }
    }
}
