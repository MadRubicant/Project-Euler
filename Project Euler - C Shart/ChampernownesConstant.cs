using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_Euler___C_Sharp {
    class ChampernownesConstant {
        public static long Product() {
            StringBuilder ConstantBuild = new StringBuilder();
            for (int i = 1; i < 1000000; i++) {
                ConstantBuild.Append(i);
            }
            string Constant = ConstantBuild.ToString();
            long product = int.Parse(Constant[0].ToString()) * int.Parse(Constant[9].ToString()) * int.Parse(Constant[99].ToString()) * int.Parse(Constant[999].ToString())
                * int.Parse(Constant[9999].ToString()) * int.Parse(Constant[99999].ToString()) * int.Parse(Constant[999999].ToString());
            return product;
        }
    }
}
