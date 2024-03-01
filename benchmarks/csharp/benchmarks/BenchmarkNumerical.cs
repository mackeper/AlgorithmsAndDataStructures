using System;
using System.Collections.Generic;
using BenchmarkDotNet.Attributes;

namespace benchmark {
  public class BenchmarkNumerical
  {
    private List<int> ilist_;
    private List<long> llist_;

    [Params(10, 100, 1000, 10000, 100000, 1000000, 10000000)]
    public int N;

    public BenchmarkNumerical()
    {
      ilist_ = new List<int>();
      llist_ = new List<long>();
    }

    private int f(int d) => d * d;
    private long f(long d) => d * d;

    [IterationSetup]
    public void Setup()
    {
      for (var i = 0; i <= N; i++)
      {
        ilist_.Add(f(i));
        llist_.Add(f((long)i));
      }
    }

    [IterationCleanup]
    public void Cleanup()
    {
      ilist_.Clear();
    }

    [Benchmark]
    public int testInt()
    {
      var sum = 0;
      for (int i = 0; i < N; i++)
      {
        sum += ilist_[i];
      }
      return sum;
    }

    [Benchmark]
    public long testLong()
    {
      long sum = 0;
      for (int i = 0; i < N; i++)
      {
        sum += llist_[i];
      }
      return sum;
    }
  }
}