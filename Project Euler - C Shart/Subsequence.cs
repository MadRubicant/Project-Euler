using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_Euler___C_Sharp {
    class Subsequence {
        public static int MinimumSubsequenceSum(int[] Sequence) {
            int minsum = 0, sum = 0;
            int minnum = Sequence[0];
            foreach (int i in Sequence) {
                sum += i;
                if (sum < minsum)
                    minsum = sum;
                if (sum > 0)
                    sum = 0;
                if (minnum > i)
                    minnum = i;
            }
            if (minsum > 0)
                return minnum;
            return minsum;
        }

        public static int MinimumPositiveSubsequenceSum(int[] Sequence) {
            int WorkingSum = 0;
            int MinimumSum = 0;
            for (int i = 0; i < Sequence.Length; i++) {
                for (int j = i; j < Sequence.Length; j++) {
                    WorkingSum += Sequence[i];
                    if (WorkingSum < MinimumSum && WorkingSum >= 0)
                        MinimumSum = WorkingSum;
                }
            }
            return Math.Max(WorkingSum, 0);
        }

        public static int MinimumSubsequenceProduct(int[] Sequence) {
            return MinimumSubsequenceProduct(new ArraySegment<int>(Sequence));
        }

        static int MinimumSubsequenceProduct(ArraySegment<int> Sequence) {
            if (Sequence.Count == 1)
                return Sequence.Array[Sequence.Offset];
            int Middle = Sequence.Count / 2;
            int LeftProduct = MinimumSubsequenceProduct(new ArraySegment<int>(Sequence.Array, Sequence.Offset, Middle));
            int RightProduct = MinimumSubsequenceProduct(new ArraySegment<int>(Sequence.Array, Sequence.Offset + Middle, Middle));
            
            int MiddleProduct = 1;
            int MiddleLeftProduct = 1;
            int TempLeftProduct = 1;
            for (int i = Middle; i >= Sequence.Offset; i--) {
                TempLeftProduct *= Sequence.Array[i];
                if (TempLeftProduct < MiddleLeftProduct)
                    MiddleLeftProduct = TempLeftProduct;
            }

            int MiddleRightProduct = 1;
            int TempRightProduct = 1;
            for (int i = Middle + 1; i < Sequence.Offset + Sequence.Count; i++) {
                TempRightProduct *= Sequence.Array[i];
                if (TempRightProduct < MiddleRightProduct)
                    MiddleRightProduct = TempRightProduct;
            }
            MiddleProduct = MiddleLeftProduct * MiddleRightProduct;
            return Math.Min(Math.Min(LeftProduct, MiddleProduct), RightProduct);
        }

        public static int MinimumSubSequenceProductNaive(int[] Sequence) {
            int MinimumProduct = Sequence[0];
            for (int i = 0; i < Sequence.Length; i++) {
                int WorkingProduct = 1;
                for (int j = i; j < Sequence.Length; j++) {
                    WorkingProduct *= Sequence[j];
                    if (WorkingProduct < MinimumProduct)
                        MinimumProduct = WorkingProduct;
                }
            }
            return MinimumProduct;
        }
    }
}
