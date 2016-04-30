using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_Euler___C_Sharp {
    static class RandomSequence {
        public static int[] RandomList(int length) {
            List<int> numbers = new List<int>(length);
            Random rand = new Random();
            for (int i = 0; i < length; i++) {
                numbers.Add(rand.Next(-20, 20));
            }
            return numbers.ToArray();
        }
    }
}
