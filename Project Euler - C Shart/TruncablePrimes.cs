using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_Euler___C_Sharp {
    class TruncablePrimes {
        public static int primes() {
            HashSet<int> primeList = new HashSet<int>();
            primeList.UnionWith(Primes.primeRange(10000000));
            List<string> primeStrings = Primes.primeRange(10000000).Select<int, string>(x => x.ToString()).ToList<string>();
            int sum = 0;
            StringBuilder reversed = new StringBuilder();
            foreach (string s in primeStrings) {
                string workingstr = string.Copy(s);
                string backworkingstr = reversed.Append(string.Copy(workingstr).Reverse<char>().ToArray<char>()).ToString();
                reversed.Clear();
                bool allPrime = true;
                //Console.WriteLine(s);
                while (workingstr.Length > 1 && backworkingstr.Length > 1) {
                    workingstr = workingstr.Remove(workingstr.Length - 1);
                    backworkingstr = backworkingstr.Remove(backworkingstr.Length - 1);
                    //Console.WriteLine("{0}, {1}", workingstr, backworkingstr);
                    if (!primeList.Contains(int.Parse(workingstr)) || !primeList.Contains(int.Parse(backworkingstr))) {
                        allPrime = false;
                        break;
                    }
                }
                if (allPrime == true) {
                    Console.WriteLine(s);
                    sum += int.Parse(s);
                }
            }

            return sum;
        }
    }
}
