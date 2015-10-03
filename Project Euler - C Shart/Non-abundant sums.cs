using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Project_Euler___C_Sharp {
    static class NonAbundSums {
       /*A perfect number is a number for which the sum of its proper divisors is exactly equal to the number.
        * For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
        * A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

        * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24.
        * By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers.
        * However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed
        * as the sum of two abundant numbers is less than this limit.

        * Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.*/
        public static int Sums() {
            int sum = 0;
            int bound = 28123;
            List<int> abundant = new List<int>();
            // True means it's not a sum, false means it is and we're skipping it
            Dictionary<int, bool> allNums = new Dictionary<int, bool>();            
            
            for (int i = 1; i < bound; i++) {
                allNums.Add(i, true);
            }
            for (int i = 1; i < bound; i++) {
                if (Abundant(i)) {
                    abundant.Add(i);
                }
            }
            // Sum all abundant numbers against each other, flag them ones in allNums
            foreach (int i in abundant) {
                foreach (int j in abundant) {
                    allNums[i + j] = false;
                }
            }
            // Woo, n^2 complexity. Maybe worse
                //Console.WriteLine("{0} is abundant", abundant[i]);
           
            
            foreach (KeyValuePair<int, bool> i in allNums) {
                if (i.Value == true) {
                    sum += i.Key;
                }
            }
                return sum;
        }


        static List<int> getFactors(int num) {
            List<int> factors = new List<int>();
            factors.Add(1);
            //Console.WriteLine(factors[0]);
            for (int i = 2; i <= num / 2; i++) {
                if (num % i == 0) {
                    factors.Add(i);
                }
            }
            /*foreach (int i in factors) {
                Console.Write("{0}, ", i);
            }
            Console.Write("\n");*/
            return factors;
        }

        static bool Abundant(int num) {
            if (getFactors(num).Sum() > num) {
                return true;
            }
            else return false;
        }
    }
}
