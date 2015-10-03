using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace Project_Euler___C_Sharp {
    class Distinct_Powers {
        public static int DistinctPowers(int a, int b) {
            HashSet<BigInteger> powers = new HashSet<BigInteger>();
            for (int i = 2; i <= a; i++) {
                for (int j = 2; j <= b; j++) {
                    powers.Add(BigInteger.Pow(i, j));
                }
            }
            return powers.Count;
        }
    }
}
