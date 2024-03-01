``` ini

BenchmarkDotNet=v0.12.1, OS=ubuntu 18.04
AMD Ryzen 5 2600X, 1 CPU, 12 logical and 6 physical cores
.NET Core SDK=3.1.402
  [Host]     : .NET Core 3.1.8 (CoreCLR 4.700.20.41105, CoreFX 4.700.20.41903), X64 RyuJIT
  Job-IMXWYV : .NET Core 3.1.8 (CoreCLR 4.700.20.41105, CoreFX 4.700.20.41903), X64 RyuJIT

InvocationCount=1  UnrollFactor=1  

```
|   Method |        N |          Mean |        Error |       StdDev |       Median |
|--------- |--------- |--------------:|-------------:|-------------:|-------------:|
|  **testInt** |       **10** |      **66.67 ns** |     **25.64 ns** |     **72.73 ns** |     **100.0 ns** |
| testLong |       10 |      69.39 ns |     19.32 ns |     56.36 ns |     100.0 ns |
|  **testInt** |      **100** |      **88.37 ns** |     **11.85 ns** |     **32.24 ns** |     **100.0 ns** |
| testLong |      100 |     175.81 ns |     33.14 ns |     94.01 ns |     150.0 ns |
|  **testInt** |     **1000** |     **704.26 ns** |     **45.37 ns** |    **129.44 ns** |     **700.0 ns** |
| testLong |     1000 |   1,016.49 ns |     69.24 ns |    200.87 ns |     900.0 ns |
|  **testInt** |    **10000** |   **5,578.57 ns** |    **100.69 ns** |     **89.26 ns** |   **5,550.0 ns** |
| testLong |    10000 |   7,926.53 ns |    162.18 ns |    323.89 ns |   7,800.0 ns |
|  **testInt** |   **100000** |  **54,443.75 ns** |  **1,026.96 ns** |  **1,008.61 ns** |  **54,100.0 ns** |
| testLong |   100000 |  77,700.00 ns |  1,521.16 ns |  1,923.77 ns |  77,500.0 ns |
|  **testInt** |  **1000000** | **581,842.86 ns** | **11,557.94 ns** | **16,576.05 ns** | **580,100.0 ns** |
| testLong |  1000000 | 900,584.04 ns | 22,644.37 ns | 64,605.67 ns | 893,700.0 ns |
|  **testInt** | **10000000** |            **NA** |           **NA** |           **NA** |           **NA** |
| testLong | 10000000 |            NA |           NA |           NA |           NA |

Benchmarks with issues:
  Benchmark.testInt: Job-IMXWYV(InvocationCount=1, UnrollFactor=1) [N=10000000]
  Benchmark.testLong: Job-IMXWYV(InvocationCount=1, UnrollFactor=1) [N=10000000]
