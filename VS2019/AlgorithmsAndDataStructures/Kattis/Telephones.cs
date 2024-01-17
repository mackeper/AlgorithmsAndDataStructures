using System;
using System.Collections.Generic;
using System.IO;

namespace Kattis
{
    public class Telephones
    {
        public static void Run(TextReader tr, TextWriter tw)
        {
            var line = tr.ReadLine();
            while (line != null)
            {
                var nm = line.Split(' ');
                var N = int.Parse(nm[0]);
                var M = int.Parse(nm[1]);

                if (N == 0 && M == 0)
                    return;

                var l = new SortedDictionary<int, int>();
                for (int i = 0; i < N; i++)
                {
                    var callData = Array.ConvertAll(tr.ReadLine().Split(' '), s => int.Parse(s));
                    if (!l.ContainsKey(callData[2]))
                        l.Add(callData[2], 0);
                    l[callData[2]] += 1;

                    if (!l.ContainsKey(callData[2] + callData[3]))
                        l.Add(callData[2] + callData[3], 0);
                    l[callData[2]+callData[3]] -= 1;
                }

                for (int i = 0; i < M; i++)
                {
                    var lastStart = 0;
                    var sum = 0;
                    var res = sum;
                    var intervalData = Array.ConvertAll(tr.ReadLine().Split(' '), s => int.Parse(s));
                    foreach (var item in l)
                    {
                        res = sum > res &&
                          ((lastStart <= intervalData[0] && intervalData[0] < item.Key) ||
                           (lastStart <= intervalData[0] + intervalData[1] && intervalData[0] + intervalData[1] < item.Key))
                          ? sum : res;
                        lastStart = item.Key;
                        sum += item.Value;
                    }
                    tw.WriteLine(res);
                }
                line = tr.ReadLine();
            }
        }

        static void Main(string[] args)
        {
            Run(Console.In, Console.Out);
        }
    }
}
