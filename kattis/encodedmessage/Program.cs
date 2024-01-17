using System;

namespace encodedmessage
{
    public class Program {

        public static string Solve(string s)
        {
            var size = (int)Math.Sqrt(s.Length);
            var decoded = new char[s.Length];
            for (var col = 0; col < size; col++)
            {
                for (var row = 0; row < size; row++)
                {
                    var current = row*size+col;
                    var new_row = (size-1)-col;
                    var new_col = row;
                    var goal = new_row*size+new_col;
                    decoded[goal] = s[current];
                }
            }
            var result = string.Concat(decoded);
            return result;
        }

        public static void Main()
        {
            var N = Int64.Parse(Console.ReadLine());
            for (var i = 0; i < N; i++)
            {
                var str = Console.ReadLine();
                Console.WriteLine(Solve(str));
            }
        }
    }
}