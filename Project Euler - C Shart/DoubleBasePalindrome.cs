using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text;

namespace Project_Euler___C_Sharp {
    class DoubleBasePalindrome {
        public static int PalindromeSum(int range) {
            List<string> Base10 = new List<string>();
            List<string> Base2 = new List<string>();
            for (int i = 0; i < range; i++) {
                Base10.Add(i.ToString());
                Base2.Add(Convert.ToString(i, 2));
            }
            var Palindrome10 = Base10.Where<string>(x => IsPalindrome(x));
            var Palindrome2 = Base2.Where<string>(x => IsPalindrome(x));

            
            var Int10 = Palindrome10.Select<string, int>(x => int.Parse(x));
            var Int2 = Palindrome2.Select<string, int>(x => Convert.ToInt32(x, 2));

            /*foreach (int i in Int10.Intersect<int>(Int2)) {
                Console.Write("{0}, ", i);
            }*/
            return Int10.Intersect<int>(Int2).Sum();
        }
        static bool IsPalindrome(string input) {
            StringBuilder reversed = new System.Text.StringBuilder();
            reversed.Append(input.Reverse<char>().ToArray<char>());
            //Console.Write("{0}, ", reversed.ToString());
            if (reversed.ToString() == input) return true;
            else return false;
        }
    }
}
