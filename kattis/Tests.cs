using Xunit;

namespace ConsoleApp {
    public static class Tests {
        // Have not yet figured out how to test console input/output
        // with getchar_unlocked and putchar_unlocked
        [Fact]
        public static void TestMethod() {
            var a = 1;
            var b = 2;
            Assert.Equal(3, a + b);
        }

    }
}
