using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_Euler___C_Sharp {
    class LatticePaths {
        public static long numPaths(int width, int height) {
            long[,] grid = new long[width + 1, height + 1];

            for (int i = 0; i < width; i++) {
                grid[i, width] = 1;
            }
            for (int i = 0; i < height; i++) {
                grid[height, i] = 1;
            }
                for (int i = width - 1; i >= 0; i--) {
                    for (int j = height - 1; j >= 0; j--) {
                        grid[i, j] = grid[i + 1, j] + grid[i, j + 1];
                    }
                }
            return grid[0, 0];
        }
    }
}
