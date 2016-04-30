using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_Euler___C_Sharp {
    class CircularPrimes {
        public static int Circulars(int range) {
            int count = 0;
            HashSet<int> primes = new HashSet<int>();
            primes.UnionWith(Primes.primeRange(range));
            HashSet<string> stringprimes = new HashSet<string>();
            stringprimes.UnionWith(primes.Select<int, string>(x => x.ToString()));

            stringprimes.RemoveWhere(x => x.Contains('2') || x.Contains('4') || x.Contains('6') || x.Contains('8') || x.Contains('0'));

            foreach (string number in stringprimes) {
                string varnumber = number.Substring(0);
                bool allPrime = true;
                for (int i = 0; i < number.Length; i++) {
                    char c = varnumber.First<char>();
                    varnumber += c;
                    varnumber = varnumber.Remove(0, 1);
                    if (!primes.Contains(int.Parse(varnumber))) {
                        //Console.WriteLine(number);
                        allPrime = false;
                        break;
                    }
                }
                if (allPrime == true) {
                    count++;
                }
                allPrime = true;
            }
            return count + 1;
        }
    }
}
