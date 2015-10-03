using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace Project_Euler___C_Sharp {
    class Amicable_Numbers {
        public static int Numbers(int range) {
            List<int[]> divs = new List<int[]>();
            int i = 0;
            // Find the divisors of all the numbers in range
            for (; i < 4; i++) {
                int[] list = new int[1];
                if (i == 0)
                    list[0] = 0;
                else
                    list[0] = 1;
                divs.Add(list);
            }
            while (i < range) {
                List<int> i_divs = new List<int>();
                for (int j = 1; j < i / 2 + 1; j++) {
                    //Console.WriteLine("{0}, {1}", i, j);
                    if (i % j == 0) {
                        //Console.WriteLine("{0}, {1}", i, j);
                        i_divs.Add(j);
                    }
                }
                //Console.Write("{0}: ", i);
                //foreach (int integer in i_divs)
                //    Console.Write("{0}, ", integer);
                //Console.WriteLine();

                divs.Add(i_divs.ToArray());
                i++;
            }
            //for (i = 0; i < range; i++) {
            //    Console.Write("{0}, sum {1}: ", i, divs[i].Sum());
            //    foreach (int integer in divs[i]) {
            //        Console.Write("{0}, ", integer);
            //    }
            //    Console.WriteLine();
            //}
            int sum = 0;
            for (i = 0; i < range; i++) {
                for (int j = 0; j < range; j++) {
                    if (divs[i].Sum() == j && divs[j].Sum() == i && i != j) {
                        Console.WriteLine("{0}, {1}", i, j);
                        sum += i;
                    }
                }
            }
            return sum;
        }
    }
}
