using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using BenchmarkDotNet.Attributes;
using BenchmarkDotNet.Columns;
using BenchmarkDotNet.Configs;
using BenchmarkDotNet.Exporters;
using BenchmarkDotNet.Exporters.Csv;
using BenchmarkDotNet.Loggers;
using BenchmarkDotNet.Running;

namespace benchmark
{
  public class Config : ManualConfig
  {
    public Config()
    {
      var dc = DefaultConfig.Instance;
      AddExporter(CsvMeasurementsExporter.Default);
      AddExporter(RPlotExporter.Default);
      foreach (var x in dc.GetExporters())
      {
        AddExporter(x);
      }

      foreach (var x in dc.GetJobs())
      {
        AddJob(x);
      }

      foreach (var x in dc.GetHardwareCounters())
      {
        AddHardwareCounters(x);
      }

      foreach (var x in dc.GetFilters())
      {
        AddFilter(x);
      }

      foreach (var x in dc.GetDiagnosers())
      {
        AddDiagnoser(x);
      }

      foreach (var x in dc.GetLoggers())
      {
        AddLogger(x);
      }
      foreach (var cp in dc.GetColumnProviders())
      {
        AddColumnProvider(cp);
      }
    }
  }

  class Program
  {

    public static void DoubleToLongBits(double argument)
    {
      long longValue = BitConverter.DoubleToInt64Bits(argument);
      string bits = Convert.ToString(longValue, 2);
      string sign = bits.Substring(0, 1);
      string exponent = bits.Substring(1, 11);
      string matissa = bits.Substring(12, bits.Length-12);
      Console.WriteLine($"{argument}");
      Console.WriteLine($"{bits.Length}");
      Console.WriteLine($"{bits}");
      Console.WriteLine($"{sign} {exponent} {matissa}\n");
    }

    public static double ConvertMtoCM(double meter) => meter * 100;

    [System.Diagnostics.CodeAnalysis.SuppressMessage("Minor Code Smell", "S1481:Unused local variables should be removed", Justification = "<Pending>")]
    [System.Diagnostics.CodeAnalysis.SuppressMessage("Style", "IDE0059:Unnecessary assignment of a value", Justification = "<Pending>")]
    static void Main(string[] args)
    {
      var summary1 = BenchmarkRunner.Run<BenchmarkNumerical>(new Config());
    }
  }
}
