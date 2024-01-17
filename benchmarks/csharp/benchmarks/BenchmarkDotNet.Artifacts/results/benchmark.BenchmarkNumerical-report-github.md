``` ini

BenchmarkDotNet=v0.12.1, OS=ubuntu 18.04
AMD Ryzen 5 2600X, 1 CPU, 12 logical and 6 physical cores
.NET Core SDK=3.1.402
  [Host]     : .NET Core 3.1.8 (CoreCLR 4.700.20.41105, CoreFX 4.700.20.41903), X64 RyuJIT
  Job-YPLPSA : .NET Core 3.1.8 (CoreCLR 4.700.20.41105, CoreFX 4.700.20.41903), X64 RyuJIT

InvocationCount=1  UnrollFactor=1  

```
|   Method |        N |          Mean |        Error |       StdDev |          Median |
|--------- |--------- |--------------:|-------------:|-------------:|----------------:|
|  **testInt** |       **10** |      **34.02 ns** |     **21.62 ns** |     **62.73 ns** |       **0.0000 ns** |
| testLong |       10 |      38.14 ns |     16.83 ns |     48.83 ns |       0.0000 ns |
|  **testInt** |      **100** |     **129.90 ns** |     **23.42 ns** |     **67.95 ns** |     **100.0000 ns** |
| testLong |      100 |      82.89 ns |     14.89 ns |     37.91 ns |     100.0000 ns |
|  **testInt** |     **1000** |     **651.65 ns** |     **25.14 ns** |     **70.49 ns** |     **700.0000 ns** |
| testLong |     1000 |     816.33 ns |     36.74 ns |    107.16 ns |     800.0000 ns |
|  **testInt** |    **10000** |   **5,500.00 ns** |     **76.64 ns** |     **67.94 ns** |   **5,500.0000 ns** |
| testLong |    10000 |   7,881.25 ns |    162.79 ns |    321.34 ns |   7,750.0000 ns |
|  **testInt** |   **100000** |  **54,929.63 ns** |    **949.82 ns** |  **1,331.52 ns** |  **54,500.0000 ns** |
| testLong |   100000 |  77,058.33 ns |  1,451.64 ns |  1,133.34 ns |  76,800.0000 ns |
|  **testInt** |  **1000000** | **587,328.57 ns** | **11,079.21 ns** | **25,456.33 ns** | **579,600.0000 ns** |
| testLong |  1000000 | 890,234.78 ns | 17,587.95 ns | 33,886.01 ns | 889,600.0000 ns |
|  **testInt** | **10000000** |            **NA** |           **NA** |           **NA** |              **NA** |
| testLong | 10000000 |            NA |           NA |           NA |              NA |

Benchmarks with issues:
  BenchmarkNumerical.testInt: Job-YPLPSA(InvocationCount=1, UnrollFactor=1) [N=10000000]
  BenchmarkNumerical.testLong: Job-YPLPSA(InvocationCount=1, UnrollFactor=1) [N=10000000]
