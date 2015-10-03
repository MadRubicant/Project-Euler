using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace Project_Euler___C_Sharp {
    class DigitCancellingFractions {
        public int Denominator() {
            List<int> Denominators = new List<int>();
            List<int> Numerators = new List<int>();

            for (int i = 10; i < 100; i++) {
                for (int j = 10; j < 100; j++) {

                }
            }



                return 0;
        }
    }

    class Fraction {
        public int Numerator;
        public int Denominator;

        public Fraction(int num, int denom) {
            Numerator = num;
            Denominator = denom;
        }

        public static Fraction operator +(Fraction left, Fraction right) {
            return new Fraction(left.Numerator * right.Denominator + left.Denominator + right.Numerator, left.Denominator + right.Denominator);
        }

        public static Fraction operator -(Fraction left, Fraction right) {
            return new Fraction(left.Numerator * right.Denominator - left.Denominator + right.Numerator, left.Denominator + right.Denominator);
        }

        
    }
}
