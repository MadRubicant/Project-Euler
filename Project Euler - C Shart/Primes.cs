using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace Project_Euler___C_Sharp {
    class Primes {
       /* public static int[] primeRange(int range) {
            List<int> Primes = new List<int>();
            Primes.Add(2);
            for (int i = 2; i < range; i++) {
                bool isPrime = true;
                foreach (int prime in Primes) {
                    if (i % prime == 0) {
                        isPrime = false;
                        break;
                    }
                }
                if (isPrime == true)
                    Primes.Add(i);
            }
            return Primes.ToArray();
        }*/
        public static int[] primeRange(int range) {
            List<int> Primes = new List<int>();
            HashSet<int> Composites = new HashSet<int>();
            int prime = 2;
            for (int i = 2; i < range; i++) {
                Primes.Add(i);
            }
            while (prime * prime < range) {
                foreach (int number in Primes) {
                    Composites.Add(number * prime);
                }
                Primes = Primes.Except<int>(Composites).ToList<int>();
                Composites.Clear();
                prime = Primes.Where<int>(x => x > prime).Min();
            }
            return Primes.ToArray();
        }
    }
}
