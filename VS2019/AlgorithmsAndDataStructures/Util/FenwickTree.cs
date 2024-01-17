using System;

namespace Util
{
    public class FenwickTree
    {
        public int Size { get; }
        private int[] table;
        public FenwickTree(int size) { Size = size; table = new int[size]; }
        public void Update(int i, int delta) { i += 1; while (i < Size) { table[i] += delta; i += i & -i; } }
        public int Sum(int i) { int sum = 0; while (i > 0) { sum += table[i]; i -= i & -i; } return sum; }
        public int SumRange(int i, int j) => Sum(j) - Sum(i - 1);
    }
}
