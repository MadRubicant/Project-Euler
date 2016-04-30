using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Text.RegularExpressions;

namespace Project_Euler___C_Sharp {
    class TriangleNumbers {
        public static int[] Numbers(int range) {
            List<int> nums = new List<int>();
            for (int i = 1; i < range; i++) {
                int tri = (int)(i / 2.0f * (1 + i));
                nums.Add(tri);
                Console.WriteLine(tri);
            }
            return nums.ToArray();
        }


        public static int CodedTriangles() {
            var NumberFile = File.Open("p042_words.txt", FileMode.Open);
            StreamReader file = new StreamReader(NumberFile);
            string AllWords = file.ReadToEnd();
            Regex splitWordsRegex = new Regex("\\b\\w*\\b");
            MatchCollection splitwords = splitWordsRegex.Matches(AllWords);
            //string[] words = new string[splitwords.Count];
            //splitwords.CopyTo(words, 0);

            HashSet<int> trianglenumbers = new HashSet<int>();
            trianglenumbers.UnionWith(Numbers(50));

            int totalTriangles = 0;
            foreach (Match s in splitwords) {
                if (trianglenumbers.Contains(WordValue(s.Value))) {
                    totalTriangles++;
                }
            }

            return totalTriangles;
        }

        public static int WordValue(string word) {
            int sum = 0;
            foreach (char c in word) {
                if (!Char.IsLetter(c))
                    throw (new FormatException("Did not receive an alphabetic character"));
                sum += c - 'A' + 1;
                //Console.Write("{0}", c - 'A');
            }
            //Console.WriteLine(word);
            return sum;
        }
    }
}
