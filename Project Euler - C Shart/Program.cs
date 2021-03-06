﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Timers;

namespace Project_Euler___C_Sharp {
    class Program {
        static void Main(string[] args) {
            DateTime t = DateTime.Now;
            switch (args.Length) {
                case 0:
                    Console.WriteLine("Bad input; no arguments");
                    break;

                case 1:
                    if (args[0] == "--Nonabundant-sums") {
                        Console.WriteLine(NonAbundSums.Sums());
                    }

                    else if (args[0] == "--lexo-permutations") {
                        Console.WriteLine(lexicographicPermutation.getMillionth());
                    }

                    else if (args[0] == "--digit-fifth-powers") {
                        Console.WriteLine(DigitFifthSums.FifthSums());
                    }
                    else if (args[0] == "--truncable-primes") {
                        Console.WriteLine(TruncablePrimes.primes());
                    }
                    else if (args[0] == "--champ-constant") {
                        Console.WriteLine(ChampernownesConstant.Product());
                    }
                    else if (args[0] == "--coded-triangle-numbers") {
                        Console.WriteLine(TriangleNumbers.CodedTriangles());
                    }
                    break;

                case 2:
                    if (args[0] == "--n-digit-fib") {
                        Console.WriteLine(OneKDigitFib.NthDigitFib(int.Parse(args[1])));
                    }
                    else if (args[0] == "--number-spiral") {
                        Console.WriteLine(NumberSpirals.spiralSum(int.Parse(args[1])));
                    }
                    else if (args[0] == "--amicable-numbers") {
                        Console.WriteLine(Amicable_Numbers.Numbers(int.Parse(args[1])));
                    }
                    else if (args[0] == "--primes") {
                        foreach (int i in Primes.primeRange(int.Parse(args[1])))
                            Console.Write("{0},  ", i);
                    }
                    else if (args[0] == "--circular-primes") {
                        Console.WriteLine(CircularPrimes.Circulars(int.Parse(args[1])));
                    }
                    else if (args[0] == "--double-base-palindromes") {
                        Console.WriteLine(DoubleBasePalindrome.PalindromeSum(int.Parse(args[1])));
                    }
                    else if (args[0] == "--minimum-subseq-product") {
                        int[] Sequence = RandomSequence.RandomList(int.Parse(args[1]));
                        Console.Write("Array generated: ");
                        foreach (int i in Sequence)
                            Console.Write("{0}, ", i);
                        Console.WriteLine();
                        Console.WriteLine(Subsequence.MinimumSubSequenceProductNaive(Sequence));
                        Console.WriteLine(Subsequence.MinimumSubsequenceProduct(Sequence));
                    }
                    /*else if (args[0] == "--coin-sums") {
                        Console.WriteLine(CoinSums.Sums(int.Parse(args[1])));
                    }*/
                    break;
                case 3:
                    if (args[0] == "--distinct-powers") {
                        Console.WriteLine(Distinct_Powers.DistinctPowers(int.Parse(args[1]), int.Parse(args[2])));
                    }
                    else if (args[0] == "--lattice-paths") {
                        Console.WriteLine(LatticePaths.numPaths(int.Parse(args[1]), int.Parse(args[2])));
                    }
                    break;
            }
            Console.WriteLine("Time elapsed: {0}", t - DateTime.Now);
            Console.Read();
        }
    }
}
