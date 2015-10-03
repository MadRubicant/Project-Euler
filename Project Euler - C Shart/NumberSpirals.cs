using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace Project_Euler___C_Sharp {
    class NumberSpirals {
        internal enum Direction {Right, Left, Up, Down};

        public static int spiralSum(int size) {
            List<List<int>> grid = new List<List<int>>(size);
            for (int i = 0; i < size; i++) {
                grid.Add(new List<int>(size));
                for (int j = 0; j < size; j++) {
                    grid[i].Add(0);
                }
            }
            Direction dir = Direction.Left;
            bool filled = false;
            int currentNumber = size * size;
            int currentSize = size;
            int numMade = 0;
            int x = size - 1;
            int y = 0;

            while (filled == false) {
                grid[y][x] = currentNumber;
                currentNumber--;
                numMade++;
                if (currentNumber == 0) {
                    filled = true;
                }
                if (numMade == currentSize) {
                    numMade = 0;
                    switch (dir) {
                        case Direction.Left:
                            dir = Direction.Down;
                            currentSize--;
                            break;
                        case Direction.Down:
                            dir = Direction.Right;
                            break;
                        case Direction.Right:
                            dir = Direction.Up;
                            currentSize--;
                            break;
                        case Direction.Up:
                            dir = Direction.Left;
                            break;
                    }
                }
                switch (dir) {
                    case Direction.Left:
                        x--;
                        break;
                    case Direction.Down:
                        y++;
                        break;
                    case Direction.Right:
                        x++;
                        break;
                    case Direction.Up:
                        y--;
                        break;
                }
            }
            int sum = 0;
            x = 0;
            y = 0;
            HashSet<int> nums = new HashSet<int>();
            while (y < size && x < size) {
                /*Console.Write(grid[y][x]);
                Console.Write(", ");*/
                nums.Add(grid[y][x]);
                x++;
                y++;
            }
            //Console.WriteLine();
            x = size - 1;
            y = 0;
            while (y < size && x >= 0) {
                //Console.Write("{0}, ", grid[y][x]);
                nums.Add(grid[y][x]);
                y++;
                x--;
            }
            sum = nums.Sum();
           // Console.WriteLine();

            return sum;
        }
    }
}
