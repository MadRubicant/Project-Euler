using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_Euler___C_Sharp {
    static class lexicographicPermutation {
        /*A permutation is an ordered arrangement of objects. 
         *For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4.
         *If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. 
         *The lexicographic permutations of 0, 1 and 2 are:

         * 012   021   102   120   201   210

         * What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
         */
        public static long getMillionth() {
            List<long> perms = buildPermutations();
            perms.Sort();
            return perms[999999];
            
        }

        static List<long> buildPermutations() {
            char[] chars = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}; //
            List<long> perms = new List<long>();

            List<CharNode> tree = new List<CharNode>();
            foreach (char c in chars) {
                CharNode cn = new CharNode(c, chars.ToList<char>());
                tree.Add(cn);
            }
            foreach (CharNode cn in tree) {
                //Console.WriteLine(cn.getTree().Count);
                foreach (string s in cn.getTree()) {
                    //Console.WriteLine(s);
                    perms.Add(long.Parse(s));
                }
            }
                return perms;
        }


        class CharNode {
            char data;
            CharNode[] children;

            public CharNode(char c) {
                data = c;
            }
            public CharNode(char c, List<char> chars) {
                //Console.WriteLine("In constructor, array length is: {0}", chars.Count);
                data = c;
                chars.Remove(c);
                if (chars.Count > 1) {
                    children = new CharNode[chars.Count];
                    for (int i = 0; i < chars.Count; i++) {
                        char nextchar = chars[i];
                        children[i] = new CharNode(nextchar, chars.ToList<char>());
                    }
                }
                else {
                    children = new CharNode[1];
                    children[0] = new CharNode(chars[0]);
                }
            }


            public List<string> getTree() {
                List<string> cur = new List<string>();
                List<string> ret = new List<string>();
                if (children == null) {
                    ret.Add(data.ToString());
                    return ret;
                }
                // Add all the child lists to the current lists
                foreach (CharNode child in children) {
                    cur.AddRange(child.getTree());
                    
                }
                for (int i = 0; i < cur.Count; i++) {
                    ret.Add(cur[i] + data.ToString());
                }
                return ret;
            }
        }
    }
}
