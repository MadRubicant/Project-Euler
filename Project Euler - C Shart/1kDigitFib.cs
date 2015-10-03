using System;
using System.Collections.Generic;
using System.Numerics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_Euler___C_Sharp {
    class OneKDigitFib {
        static BigInteger first = 1, second = 1, next;
        static int num = 2;
        static uint Fib(uint n) {
            if (n == 1 || n == 0) {
                return 1;
            }
            else { return Fib(n - 1) + Fib(n - 2); }
        }
        static private void nextFib() {
            next = first + second;
            first = second;
            second = next;
            num++;
        }
        public static string NthDigitFib(int digits) {
            while (next.ToString().Length < digits) {
                nextFib();
            }
            return num.ToString();
        }
    }
}
