using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_Euler___C_Sharp {
    class PentagonNumbers {
        public static int[] NumberRange(int range) {
            List<int> numbers = new List<int>(range);
            for (int i = 1; i <= range; i++) {
                int pent = (i * (3 * i - 1)) / 2;
                numbers.Add(pent);
            }
            return numbers.ToArray();
        }

        public static int Difference() {
            HashSet<int> PentContains = new HashSet<int>();
            var Pents = NumberRange(400);
            PentContains.UnionWith(Pents);
            return 0;
        }
    }
}
