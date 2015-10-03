using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace Project_Euler___C_Sharp {
    class DigitFifthSums {
        public static BigInteger FifthSums() {
            BigInteger totalSum = 0;
            uint[] powers = new uint[10] { 0, 1, 32, 243, 1024, 3125, 7776, 16807, 32768, 59049 };
            //uint[] powers = new uint[10] { 0, 1, 16, 81, 256, 625, 1296, 2401, 4096, 6561 };
            Dictionary<ulong, ulong> sums = new Dictionary<ulong, ulong>();
            // Dictionary of numbers and their digit power sum
            sums.Add(0, 0);
            sums.Add(1, 1);
            for (ulong i = 2; i <= 355000; i++) {
                if (i % (uint.MaxValue / 10) == 0)
                    Console.WriteLine("{0}% done processing", (double)i / (double)UInt64.MaxValue);
                
                ulong sum = 0;
                ulong number = i;
                while (number != 0) {
                    //if (sums.ContainsKey(number)) {
                    //    sum += sums[number];
                    //    break;
                    //}
                    ulong dig = number % 10;
                    sum += powers[dig];
                    number /= 10;
                }
                //sums.Add(i, sum);
                if (sum == i && sum != 1)
                    totalSum += i;
            }

            return totalSum;
        }
    }
}
